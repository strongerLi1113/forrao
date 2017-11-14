/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Y:\source\xs-robot\src\modules\log4c\log.c 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-18

** Email: q19881113@126.com 

** History: 

***************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <log.h>
const char* file = "Tarminal_File";
const char* console = "Tarminal_Console";


static log4c_category_t* category_console;
static log4c_category_t* category_file;



static log4c_category_t* category_console; 

void log_message(int priority ,const char *fmt , ...)
{
	va_list ap;
	assert(category_console != NULL);
	va_start(ap, fmt);
	log4c_category_vlog(category_console , priority , fmt , ap);
	log4c_category_vlog(category_file , priority , fmt , ap);
	va_end(ap);
}


int log_init()
{
	if (log4c_init() < 0){
		printf("log4c init fail!");
		return -1;
	}
	category_console = log4c_category_get(console);
	category_file = log4c_category_get(file);
	
	return 0;
}

void log_release()
{
	log4c_fini();	
}
