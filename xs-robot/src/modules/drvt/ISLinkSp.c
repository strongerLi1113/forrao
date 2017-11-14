/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Y:\source\xs-robot\src\modules\drvt\ISLinkSp.c 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-19

** Email: q19881113@126.com 

** History: 

***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include <ISLink.h>
#include <ISLinkSp.h>
//#include "mylog.h"



 int8_t ISLink_SpInit(ISLink_port_t* p, const char* path)
 {
 	ISLink_sp_t* sp = NULL;

	assert(p);
	assert(path);

	/* FIXME: need to free private */
	sp = (ISLink_sp_t*)malloc(sizeof(ISLink_sp_t));
	if(sp == NULL)
		return -1;

	memset(sp->spPath, 0, sizeof(sp->spPath));
	strncpy(sp->spPath, path, sizeof(sp->spPath));
 	cssl_t* s = cssl_open(path,0, 0, 115200, 8, 0, 1);
	if (!s)
	{
		free(sp);
		printf("[%s]: %s", path, cssl_geterrormsg());
		//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_ERROR, "[%s]: %s", path, cssl_geterrormsg());
		return -1;
	}

	//mylog_log(MYLOG_CATEGORY_NAME, LOG4C_PRIORITY_INFO, "[%s] open sucessful", path);
	cssl_flush(s);
	cssl_settimeout(s, 2);

	sp->s = s;
	p->privateData = sp;
	return 0;
 }


 int8_t ISLink_SpReadByte(ISLink_port_t* p,  uint8_t* data)
 {
 	int8_t ret = -1;
	ISLink_sp_t* sp = NULL;
	int c;
	
	assert(p);
	assert(data);

	sp = (ISLink_sp_t*)p->privateData;
 	c = cssl_getchar(sp->s);
	if( c != -1 )
	{
		*data = (uint8_t)c;
		//printf("%s: %02X\r\n", sp->spPath, *data);
		ret =  0;
	}

	return ret;
 }


 int8_t ISLink_SpWriteData(ISLink_port_t* p,  uint8_t* data, uint8_t datalen)
 {
 	ISLink_sp_t* sp = NULL;
	
 	assert(p);
	assert(data);

	sp = (ISLink_sp_t*)p->privateData;
	cssl_putdata(sp->s, data, datalen);  
	return 0;
 }


