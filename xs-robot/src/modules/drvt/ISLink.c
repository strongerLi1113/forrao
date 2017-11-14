/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: ISLink.c
 * 
 * DESCRIPTION:   
 * 
 * Author: Jio
 * 
 * Date: 2017-4-08
 * 
 * History: 
 * 
 * E-mail: 385426564@qq.com
 * 
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include <codec.h>
#include <ISLink.h>
#include <ISLinkSp.h>
#include <crc8.h>



#define  PREAMBLE_1 	0xEA
#define  PREAMBLE_2 	0x61
#define  EOF_1			  0x62
#define  EOF_2			  0xEB


#define VERIOSN_NO                              0


#if defined(ISLINK_DEBUG) && (ISLINK_DEBUG == 1)
char debugTxBuffer[1024];
#endif



void* ISLink_routine(void* arg);
void ISLink_ReceiveStateMachine(ISLink_t* link);



static void _ISLink_StateMachineInit(ISLinkRecStaMachine_t* m)
{
	m->receive_index = 0;
	m->receive_state = 0;
}


void ISLink_SetLinkData(ISLink_t* link, void* linkData)
{
	link->linkData = linkData;
}

void ISLink_RegisterRxNPDUCallback(ISLink_t* link, void (*rxNDPUCallback)(void* link))
{
	link->rxNDPUCallback = rxNDPUCallback;
}

int ISLink_Init(ISLink_t* link, const char* path, const char* name)
{
	assert(link);
	assert(path);

	link->p.init = ISLink_SpInit;
	link->p.readByte = ISLink_SpReadByte;
	link->p.writeData = ISLink_SpWriteData;
	cssl_start();
	init_crc8_tab();

	
	//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_DEBUG, "ISLink[%s]: init..", path);
	if(link->p.init(&link->p, path) != 0)
		return -1;

	memset(link->p.path, 0, sizeof(link->p.path));
	strncpy(link->p.path, path, sizeof(link->p.path));
	
	memset(link->name, 0, sizeof(link->name));
	strncpy(link->name, name, sizeof(link->name));
	link->linkData= NULL;
	_ISLink_StateMachineInit(&(link->state_machine));
	return 0;
}



int ISLink_Listen(ISLink_t* link)
{
	int s;

	//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_DEBUG, "link[%s]: listen..", link->p.path);
	s = pthread_create(&link->thID, NULL, ISLink_routine, (void*)link);
	if (s != 0)
	{
		//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_ERROR, "link[%s]: create thread failed", link->p.path);
		return -1;
	}

	return 0;
}


bool  ISLink_IdleTimeout(ISLink_t* link)
{
 unsigned long diff;
 struct timeval now;


 gettimeofday(&now,NULL);
 diff = 1000000 * (now.tv_sec-link->activeTimer.tv_sec)+ now.tv_usec-link->activeTimer.tv_usec;

 //printf("DIFF %ld\r\n", diff);

 return (diff < 30*1000000) ? false : true;
}


void* ISLink_routine(void* arg)
{
	ISLink_t* link = ( ISLink_t* )arg;

	/* Add by jio @ Jun 01, 2017,16:0:48 监控通道超时*/
	gettimeofday(&link->activeTimer,NULL);
	
	while(1)
	{
		////mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_DEBUG, "rxlink[%s]: running..", link->p.path);
		//printf("running...\r\n");
		ISLink_ReceiveStateMachine(link);

		/* Add by jio @ Jun 01, 2017,15:10:49  监控是否通道超时*/
		if(ISLink_IdleTimeout(link) == true)
		{
			if(link->rxIDLECallback != NULL)
				link->rxIDLECallback(link);
			
			gettimeofday(&link->activeTimer,NULL);
		}
			
	}
}



void ISLink_ReceiveStateMachine(ISLink_t* link)
{
	uint8_t data;


	assert(link);
	assert(link->p.readByte);

	//struct timeval t;
	
	//gettimeofday(&t,NULL);
	//printf("xxx%ld %ld\r\n",t.tv_sec,  t.tv_usec);
	ISLinkRecStaMachine_t* m = &link->state_machine;
	switch(m->receive_state)
	{
		case receive_state_idle:
			if( (link->p.readByte(&link->p, &data) == 0 ) &&(data == PREAMBLE_1) )
			{     
				//printf( "xs>>>>>>>>>>>>>>>>>>>>>>>>>>>> ed head_1\r\n" );                    
				m->receive_state = receive_state_head_2;
				m->receive_index = 1;
				m->crcSum = 0;
			}
			break;


    case receive_state_head_2:
		if(link->p.readByte(&link->p, &data) == 0 )
		{
			if( m->receive_index == 1)
			{
				//printf( " received head_2\r\n" ); 
				m->crcSum = update_crc8(m->crcSum, data);
				m->rxNpdu.datalen = data;
				m->receive_index = 2;
				if( (m->rxNpdu.datalen < FRAME_DECORATOR_LEN)
					|| (m->rxNpdu.datalen > MAX_APP_DATA_LEN) )
				{
					//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_WARN, "ISLink %s: unexcept state 0", link->p.path);
					/* 非法长度*/
					if(data == PREAMBLE_1)
						m->receive_state = receive_state_head_1;
					else
						m->receive_state = receive_state_idle; 
				}
				m->receive_state = receive_state_data;
			}
			else
			{
			/* 串口阻塞读， 超时重新返回idle */
				m->receive_state = receive_state_idle;
			}
		}
		break;

    case receive_state_data:
      if(link->p.readByte(&link->p, &data) == 0 )
      {
      	
			//printf("receive data\r\n");
	      if( ( m->receive_index < m->rxNpdu.datalen )  && ( m->rxNpdu.datalen < MAX_APP_DATA_LEN ) )
	      {
	              /* receive data */
	              m->crcSum = update_crc8(m->crcSum, data);
	              m->rxNpdu.data[m->receive_index++] = data;
	      }
		//intf("%d %d %d %d %d\n",m->receive_index , m->rxNpdu.datalen,data,m->crcSum,m->rxNpdu.data[m->receive_index-1]);
        if( m->receive_index == m->rxNpdu.datalen-2)
        {
          m->receive_state = receive_state_check;
        }
        else if(m->receive_index >= MAX_APP_DATA_LEN)
        {
					//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_WARN, "ISLink %s: unexcept state 2", link->p.path);
          if(data == PREAMBLE_1)
						m->receive_state = receive_state_head_1;
					else
						m->receive_state = receive_state_idle;
        }	
      }
			else
			{
				/* 串口阻塞读， 超时重新返回idle */
				m->receive_state = receive_state_idle;
			}
   
	break;
    case receive_state_check:
	    if(link->p.readByte(&link->p, &data) == 0 )
	    {
	    	//printf( " xs>>>>>>>>>> receive_state_check\r\n" ); 
				//printf("receive check %x %x\r\n", m->crcSum, data);
				if( m->crcSum == data )
				{
					m->receive_state = receive_state_eof_1;
				}
		    else
		    {
					// Should not get here
					//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_WARN, "ISLink %s: unexcept state 3", link->p.path);
					if(data == PREAMBLE_1)
						m->receive_state = receive_state_head_1;
					else
						m->receive_state = receive_state_idle;
		    }
       }
			 else
			 {
					/* 串口阻塞读， 超时重新返回idle */
					m->receive_state = receive_state_idle;
			 }
       break;
      

      case receive_state_eof_1:
        if(link->p.readByte(&link->p, &data) == 0 )
        {
				   if(data == EOF_2) 
				   {
				   //	printf( " xs>>>>>>>>>> receive_state_eof_1\r\n" ); 
							//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_INFO, "link[%s]: receive NPDU", link->p.path);
							if(link->rxNDPUCallback)
								link->rxNDPUCallback(link);

							/* Add by jio @ Jun 01, 2017,15:12:58  更新监测通道存活时间*/
							gettimeofday(&link->activeTimer,NULL);
				   }
				   else
				   {
							//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_WARN, "ISLink %s: unexcept state 5", link->p.path);
							if(data == PREAMBLE_1)
								m->receive_state = receive_state_head_1;
							else
								m->receive_state = receive_state_idle;
				   }
						
           m->receive_state = receive_state_idle;
        }
        break;

      default:
        m->receive_state = receive_state_idle;
        break;
	}

}



void ISLink_npduInit(ISnpdu_t* npdu)
{
	npdu->stx = 0xEA;
	npdu->etx = 0xEB;
}


uint32_t ISLink_apduEncode(uint8_t* buffer, ISapdu_t* apdu)
{
	uint32_t len = 0;
	uint8_t* lptr = NULL;              

	len += encode_unsigned8(&buffer[len], apdu->func_code);

	lptr = &buffer[len];                  //len  = category + code + len + datalen
	len += 1;
	
	len += encode_octet_string(&buffer[len], apdu->data, apdu->data_len);

	encode_unsigned8(lptr, len);
	return len;
}


uint32_t ISLink_npduEncode(uint8_t* buffer, ISnpdu_t* npdu)
{
	uint32_t len = 0;
	uint8_t* lptr = NULL; 

	len += encode_unsigned8(&buffer[len], npdu->stx);

	lptr = &buffer[len];     //len
	len += 1;
	
	len += encode_octet_string(&buffer[len], &(npdu->data[0]), npdu->datalen);

	/* len =  stx ~ apdu 必须在校验之前填充完毕 */
	encode_unsigned8(lptr, len  + 2);  // total  = stx   + len + apdudata + bcc + etx
	
	len += encode_unsigned8(&buffer[len],calculate_crc8(&buffer[1], len-1)); //ver ~ app  = len - stx 
	len += encode_unsigned8(&buffer[len], npdu->etx);

	
	return len;
}



void ISLink_SendApdu(ISLink_t* link, ISapdu_t* apdu)
{
	uint8_t sendBuffer[ISLINK_MAX_BUFFER_LEN];
	uint32_t len = 0;
	ISnpdu_t txNpdu;

	assert(link);
	assert(apdu);
	assert(link->p.writeData);

	ISLink_npduInit(&txNpdu);
	txNpdu.datalen = ISLink_apduEncode(&(txNpdu.data[0]), apdu);

	len = ISLink_npduEncode(sendBuffer, &txNpdu);

#if defined(ISLINK_DEBUG) && (ISLINK_DEBUG == 1)
		uint32_t i;
		for(i=0; i<len; i++)
			snprintf(&debugTxBuffer[3*i], sizeof(debugTxBuffer), "%02X ", sendBuffer[i]);
		
		//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_DEBUG, "%s[%s]Send: %s",link->name, link->p.path, debugTxBuffer);
#endif


	printf("APDU TX:");
	for(i=0; i<len; i++)
	{
		printf("%02X ", sendBuffer[i]);
	}
	printf("\r\n");

	link->p.writeData(&link->p, sendBuffer, len);
}


bool ISgw_apduDecode(uint8_t* buffer, uint16_t size, ISapdu_t* apdu)
{
	uint16_t total_app_len = 0;
	uint32_t len = 2;
	int i;
	 
	if(size < 2)
	{
		//log_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_ERROR, "ISgw apdu decode: invailed apdu..");
		return false;
	}
	
	len += decode_unsigned8(&buffer[len], &(apdu->func_code));
	len += decode_unsigned8(&buffer[len], &(apdu->data_len));
 	
	
	//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_DEBUG, "ISgw apdu decode[%d]: apdu len %d..", size, apdu->data_len);
	if( (apdu->data_len > MAX_APP_DATA_LEN-2)
		  || (apdu->data_len > (size-2) ) )
	{
		printf("ISgw apdu decode: invailed apdu..\r\n");
		return false;
	}
	apdu->data_len = apdu->data_len-2;
	decode_octet_string(&buffer[len], apdu->data, apdu->data_len);
	//printf("fun %d,len %d\n",apdu->func_code,apdu->data_len);
	return true;
}



