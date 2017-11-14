#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <string.h>


#include <ISLink.h>
#include <ISLinkSp.h>
#include <drvt.h>
#include <codec.h>

static ISLink_t g_link;
static ISapdu_t gApdu;



int wait_callback(int timeout_ms)
{
	
	while(timeout_ms--){
		//intf("%d\n",gApdu.func_code);
		usleep(1000000);
		if(!(g_link.isCallback == 0)){
			return 0;
		}
	}
	return -1;
}

int repuest_apdu(uint8_t func_code,uint8_t* data,uint8_t len)
{
	ISapdu_t apdu;
	apdu.func_code = DRVT_IMU;
	apdu.data_len = len;
	memcpy(apdu.data,data,len);
	ISLink_SendApdu(&g_link,&apdu);
	
	if(wait_callback(100000) < 0){
		printf("apdu request timeout\n");
		return -1;
	}
	
	if(g_link.isCallback == func_code){	
		return 0;
	}
	return -1;
	
}


int drvt_imu(uint8_t cmd,drvtIMU* imu)
{
	
	uint8_t data = 0x01;
	if(repuest_apdu(DRVT_IMU,&data,1) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_IMU){
		if(gApdu.data_len > 0){
			if(imu->func&0x01){
				decode_unsigned16(&gApdu.data[1],&imu->accel_x);
				decode_unsigned16(&gApdu.data[3],&imu->accel_y);
				decode_unsigned16(&gApdu.data[5],&imu->accel_z);
			}
			if(imu->func&0x02){
				decode_unsigned16(&gApdu.data[7],&imu->gyro_x);
				decode_unsigned16(&gApdu.data[9],&imu->gyro_y);
				decode_unsigned16(&gApdu.data[11],&imu->gyro_z);
			}
			if(imu->func&0x04){
				decode_unsigned32(&gApdu.data[13],&imu->pitch);
				decode_unsigned32(&gApdu.data[17],&imu->roll);
				decode_unsigned32(&gApdu.data[21],&imu->yaw);
			}
			return 0;
		}else{
			return -1;
		}
	}
	else
		return -1;

	/*int i;
	printf("app  data\n");
	for(i=0;i<gApdu.data_len;i++)
		printf("%x",gApdu.data[i]);
	printf("\n");*/
	return 0;
}


int drvt_infraredDetection(uint8_t* ifrd)
{

	uint8_t data = 0x01;
	if(repuest_apdu(DRVT_IFRD,&data,1) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_IFRD){
		if(gApdu.data_len == 1){
			*ifrd = gApdu.data[0];
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
		
	
	
	return 0;
}

int drvt_infraredSend(uint16_t ifrt)
{

	uint8_t data[2] = {0};
	encode_unsigned16(data,ifrt);	
	if(repuest_apdu(DRVT_IFRT,data,2) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_IFRT)
		return 0;	
	else{
		return -1;
	}
		
	return 0;
}

int drvt_infraredRecv(uint8_t* ifrr)
{
	uint8_t data = 0x01;
	if(repuest_apdu(DRVT_IFRR,&data,1) < 0){
		return -1;
	}
	if(gApdu.func_code == DRVT_IFRR){
		if(gApdu.data_len == 1){
			*ifrr = gApdu.data[0];
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
		
	
	
	return 0;
}


int drvt_laser(uint8_t num,uint8_t* laser_data)
{
	
	uint8_t data = num;
	if(repuest_apdu(DRVT_LASER,&data,1) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_LASER){
		if(gApdu.data_len == num){
			memcpy(laser_data,gApdu.data,num);
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
		
	
	
	return 0;
}

int drvt_move(uint8_t speed,uint8_t yaw,uint8_t action)
{
	uint8_t data[3] = {0};
	data[0] = speed;
	data[1] = yaw;
	data[2] = action;
	if(repuest_apdu(DRVT_LASER,data,3) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_MOVE){
		return 0;
	}else{
		return -1;
	}
		
	
}

int drvt_productInfo(drvtVersion* drvtInfo)
{
	uint8_t data = 1;
	if(repuest_apdu(DRVT_LASER,&data,1) < 0){
		return -1;
	}
	
	if(gApdu.func_code == DRVT_VERSION){
		if(gApdu.data_len == 8){
			decode_unsigned32(gApdu.data,&drvtInfo->sn);
			decode_unsigned16(&gApdu.data[4],&drvtInfo->sw);
			decode_unsigned16(&gApdu.data[6],&drvtInfo->hw);
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
		
	

}



void drvtLink_Callback(void* link)
{
	printf("%s\n",__func__);
	ISLink_t* drvt_link = (ISLink_t*)link; 
	
	if(ISgw_apduDecode(drvt_link->state_machine.rxNpdu.data,drvt_link->state_machine.rxNpdu.datalen,&gApdu) != 1){
		printf("error ISgw_gApduDecode fail\n");
		return;
	}
	g_link.isCallback = gApdu.func_code;
}


int drvt_init()
{
	memset(&g_link,0,sizeof(ISLink_t));

	
	if(ISLink_Init(&g_link,UART_DEV,"drvt") != 0){
		printf("ISLink_Init fail \n");
		return -1;
	}

	ISLink_RegisterRxNPDUCallback(&g_link,drvtLink_Callback);
		
	if(ISLink_Listen(&g_link) != 0){
		return -1;
	}

	return 0;
}



