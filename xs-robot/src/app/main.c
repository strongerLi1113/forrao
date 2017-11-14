/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Z:\source\xs-robot\src\app\main.c 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-24

** Email: q19881113@126.com 

** History: 

***************************************************************************/

#include <stdio.h>

#include <log.h>
#include <drvt.h>
#include <version.h>

int main()
{
	drvtIMU imu;
	log_init();
	LOG_DEBUG("%s",SOFTWARE);
	LOG_DEBUG("%sd",HARDWARE);
	drvt_init();
	

	drvt_imu(MIU_ACCEL|MIU_GYRO|MIU_MIU,&imu);
	
	return 0;
}