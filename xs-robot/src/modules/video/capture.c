/*
 * Copyright 2014-2015 china hangzhou dofar, Inc. All rights reserved.
 */


#include "capture.h"

int capture_start(CAPTURE *cap)
{
    unsigned int i;
    struct v4l2_buffer buf;
    enum v4l2_buf_type type;

    for (i = 0; i < CAP_BUFFER_NUM; i++)
    {
        memset(&buf, 0, sizeof (buf));
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;
        if (ioctl(cap->fd, VIDIOC_QUERYBUF, &buf) < 0){
            printf("VIDIOC_QUERYBUF error\n");
            return -1;
        }
	
        cap->buffers[i].length = buf.length;
        cap->buffers[i].offset = (size_t) buf.m.offset;
        cap->buffers[i].start = mmap (NULL, cap->buffers[i].length,
            PROT_READ | PROT_WRITE, MAP_SHARED,
            cap->fd, cap->buffers[i].offset);
		memset(cap->buffers[i].start, 0xFF, cap->buffers[i].length);
		
    }

    for (i = 0; i < CAP_BUFFER_NUM; i++)
    {
        memset(&buf, 0, sizeof (buf));
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
		buf.m.offset = cap->buffers[i].offset;
        if (ioctl (cap->fd, VIDIOC_QBUF, &buf) < 0) {
            printf("VIDIOC_QBUF error\n");
            return -1;
        }
    }

    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl (cap->fd, VIDIOC_STREAMON, &type) < 0) {
        printf("VIDIOC_STREAMON error\n");
        return -1;
    }
	
    return 0;
}

int capture_stop(CAPTURE* cap)
{
        enum v4l2_buf_type type;
        type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        return ioctl (cap->fd, VIDIOC_STREAMOFF, &type);
}

int capture_setup(CAPTURE* cap)
{
    struct v4l2_format fmt;
    struct v4l2_control ctrl;
    struct v4l2_streamparm parms;
	struct v4l2_crop crop;
	struct v4l2_dbg_chip_ident chip;
	struct v4l2_frmsizeenum fsize;
	struct v4l2_fmtdesc ffmt;
	struct v4l2_input inp;

	if((cap->fd = open(cap->device_name, O_RDWR, 0)) < 0){
		printf("Unable to open %s\n", cap->device_name);
		return -1;
	}
printf("dofar >>>>>>> capture0\n");
	inp.index = 0;
	if (ioctl (cap->fd, VIDIOC_S_INPUT, &inp) < 0)
	{
		printf("VIDIOC_S_INPUT %d error!\n",inp.index);
		return -1;
	}

	//VIDIOC_S_PARM			
	parms.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	parms.parm.capture.timeperframe.numerator = 1;
	parms.parm.capture.timeperframe.denominator =30;
	parms.parm.capture.capturemode = 1; //V4L2_MODE_IMAGE
					
	if (-1 == ioctl (cap->fd, VIDIOC_S_PARM, &parms)) 
	{
		printf ("VIDIOC_S_PARM error\n");	
		return -1;
	}
	printf("dofar >>>>>>> capture1\n");

    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.pixelformat = cap->format;
    fmt.fmt.pix.width = cap->width;
    fmt.fmt.pix.height = cap->height;
    fmt.fmt.pix.bytesperline = 0;
	fmt.fmt.pix.priv = 0;
	fmt.fmt.pix.sizeimage = 0;
    if (ioctl(cap->fd, VIDIOC_S_FMT, &fmt) < 0){
       printf("set format failed\n");
       return -1;
    }
printf("dofar >>>>>>> capture2\n");
	
	
    if (ioctl(cap->fd, VIDIOC_G_FMT, &fmt) < 0)
    {
            printf("get format failed\n");
            return -1;
    }
	cap->buf_len = fmt.fmt.pix.sizeimage;

    struct v4l2_requestbuffers req;
    memset(&req, 0, sizeof (req));
    req.count = CAP_BUFFER_NUM;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    if (ioctl(cap->fd, VIDIOC_REQBUFS, &req) < 0){
        printf("capture_setup: VIDIOC_REQBUFS failed\n");
        return -1;
    }
	
    return 0;
}


int capture_get_buffer(CAPTURE* cap)
{
	int ret;
	
	memset(cap->v4l_buf, 0, sizeof(struct v4l2_buffer));
	cap->v4l_buf->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	cap->v4l_buf->memory = V4L2_MEMORY_MMAP;
	if(ioctl(cap->fd, VIDIOC_DQBUF,cap->v4l_buf) <0){
		perror("VIDIOC_DQBUF\n");
		return -1;
	} 
	//printf("cap->v4l_buf %d\n",cap->v4l_buf);
	return 0;
		
}

void capture_put_buffer(CAPTURE* cap)
{
	//printf("1cap->v4l_buf %d\n",cap->v4l_buf);
	ioctl(cap->fd, VIDIOC_QBUF,cap->v4l_buf);
	
}

int main(int argc, char **argv)
{
	
	FILE * fd_y_file;
	CAPTURE *cap;
	int i;
	struct v4l2_streamparm parm;
	cap = (CAPTURE*)malloc(sizeof(CAPTURE));
	cap->v4l_buf = (struct v4l2_buffer *)malloc(sizeof(struct v4l2_buffer));
	cap->device_name = "/dev/video0";
	cap->format = V4L2_PIX_FMT_YUV420;
	cap->fps = 10;
	cap->width = 640;
	cap->height = 480;
	
	if(capture_setup(cap) <0)
		printf("err:capture_setup fail\n");

	capture_start(cap);
	
    if ((fd_y_file = fopen("camera.yuv", "wb")) ==NULL)
    {
            printf("Unable to create y frame recording file\n");
            return -1;
    }
	
	for(i=0;i<10;i++){
	
	  	capture_get_buffer(cap);
		printf("cap->buf_len %d %d\n",cap->buf_len,cap->buf_len);
		fwrite(cap->buffers[cap->v4l_buf->index].start,cap->buf_len,1, fd_y_file);
		usleep(40);
		capture_put_buffer(cap);
	}
	capture_stop(cap);
	fclose(fd_y_file);
	free(cap->v4l_buf);
	free(cap);
      
}

