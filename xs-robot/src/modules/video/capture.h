/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Z:\source\xs-robot\src\modules\video\capture.h 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-25

** Email: q19881113@126.com 

** History: 

***************************************************************************/
#ifndef __CAPTURE_H__
#define __CAPTURE_H__

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <asm/types.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <string.h>
#include <malloc.h>


#define CAP_BUFFER_NUM 3



struct cap_buffer
{
    unsigned char *start;
   	off_t offset;
    unsigned int length;
};

typedef struct {
	char* device_name;
	int fd;
	int width;
	int height;
	int format;
	int buf_len;
	int fps ;
	struct cap_buffer buffers[CAP_BUFFER_NUM];
	struct v4l2_buffer *v4l_buf;
}CAPTURE;

int capture_start(CAPTURE* cap);
int capture_stop(CAPTURE* cap);
int capture_setup(CAPTURE* cap);
int capture_get_buffer(CAPTURE* cap);
void capture_put_buffer(CAPTURE* cap);



#endif

