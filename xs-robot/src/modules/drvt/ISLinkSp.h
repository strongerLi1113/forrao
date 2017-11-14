/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: \\192.168.1.2\hedj\workspace\project\luyang\src\ISgw-beta\src\ISLinkSp.h
 * 
 * DESCRIPTION:   
 * 
 * Author: Jio
 * 
 * Date: 2017-4-10
 * 
 * History: 
 * 
 * E-mail: 385426564@qq.com
 * 
 ******************************************************************************/
#ifndef ISLINK_SP_H
#define ISLINK_SP_H

#include <cssl.h>


typedef struct ISLink_sp_S
{
	char spPath[20];
	cssl_t* s;
}ISLink_sp_t;


int8_t ISLink_SpInit(ISLink_port_t* p , const char* path);

int8_t ISLink_SpReadByte(ISLink_port_t* p,  uint8_t* data);

int8_t ISLink_SpWriteData(ISLink_port_t* p,  uint8_t* data, uint8_t datalen);


#endif

