/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Y:\source\xs-robot\src\modules\log4c\log.h 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-18

** Email: q19881113@126.com 

** History: 

***************************************************************************/
#ifndef __LOG_H__
#define __LOG_H__

#include <log4c.h> 

void log_message(int priority ,const char *fmt , ...);
int log_init();
void log_release();


#define LOG_ERROR(fmt , args...) \
        log_message(LOG4C_PRIORITY_ERROR, fmt, ##args)

#define LOG_WARN(fmt, args...) \
        log_message(LOG4C_PRIORITY_WARN, fmt , ##args)
		
#define LOG_DEBUG(fmt , args...) \
        log_message(LOG4C_PRIORITY_DEBUG, fmt , ##args)


#endif



