/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: ISLink.h
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
#ifndef ISLINK_H
#define ISLINK_H

#include <stdint.h>
#include <stdbool.h>


#define ISLINK_DEBUG        1

#define HEAD_FIELD_LEN		  1
#define BCC_LEN 			  		1
#define END_LEN 			  		1

#define MAX_APP_DATA_LEN      255
#define FRAME_DECORATOR_LEN   ( HEAD_FIELD_LEN  + BCC_LEN + END_LEN )

#define ISLINK_MAX_BUFFER_LEN	  ( FRAME_DECORATOR_LEN + MAX_APP_DATA_LEN )


typedef struct 
{
  uint8_t func_code;
  uint8_t data_len;
  uint8_t data[MAX_APP_DATA_LEN-2];
}ISapdu_t;


typedef struct
{
	uint8_t stx;
	uint8_t datalen;
	uint8_t data[MAX_APP_DATA_LEN];
	uint8_t bcc;
	uint8_t etx;
}ISnpdu_t;



typedef enum 
{
	receive_state_idle=0,
	receive_state_head_1,
	receive_state_head_2,
	receive_state_data,
	receive_state_check,
	receive_state_data_end,
	receive_state_eof_1
}ISLinkRecvState_t;


typedef struct ISLinkRecStaMachine_S
{
	ISLinkRecvState_t receive_state;
	uint8_t receive_index;
	uint8_t crcSum;
	ISnpdu_t rxNpdu;
}ISLinkRecStaMachine_t;


typedef struct ISLink_port_S
{
	int (*init)(struct ISLink_port_S* p, const char* path);
	int (*readByte)(struct ISLink_port_S* p, uint8_t* data);
	int (*writeData)(struct ISLink_port_S* p, uint8_t* data, uint8_t datalen);
	void* privateData;
	char path[50];
}ISLink_port_t;

typedef struct 
{
	ISLink_port_t p;  // link 物理port
	ISLinkRecStaMachine_t state_machine;
	void (*rxNDPUCallback)(void* link);

	struct timeval activeTimer;
	void (*rxIDLECallback)(void* link);

	char name[50];
	void* parent;
	void* linkData;
	int isCallback;
	pthread_t thID;
}ISLink_t;

int ISLink_Init(ISLink_t* link, const char* path, const char* name);

int ISLink_Listen(ISLink_t* link);

void ISLink_RegisterRxNPDUCallback(ISLink_t* link, void (*rxNDPUCallback)(void* link));

void ISLink_SetLinkData(ISLink_t* link, void* linkData);

void ISLink_SendApdu(ISLink_t* link, ISapdu_t* apdu);

bool ISgw_apduDecode(uint8_t* buffer, uint16_t size, ISapdu_t* apdu);



#endif

