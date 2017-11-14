#ifndef __DRVT__
#define __DRVT__

#include <stdint.h>

#define UART_DEV	"/dev/ttyS2"

typedef enum 
{
	DRVT_VERSION=1,
	DRVT_MOVE,
	DRVT_LASER,
	DRVT_IFRR,
	DRVT_IFRT,
	DRVT_IFRD,
	DRVT_IMU
}DRVT_FUNC;

typedef enum 
{
	ACTION_STOP=0,
	ACTION_BACK,
	ACTION_FORWARD,
	ACTION_ROT,
	ACTION_LIFT = 0x10,
	ACTION_RIGHT = 0x20
}DRVT_ACTION;


typedef enum 
{
	MIU_ACCEL=1,
	MIU_GYRO=2,
	MIU_MIU=4
}DRVT_MIU;



typedef struct {
	uint32_t sn;
	uint16_t sw;
	uint16_t hw;
}drvtVersion;


typedef struct{
	uint8_t  func;
	
	uint16_t  accel_x;
	uint16_t  accel_y;
	uint16_t  accel_z;
	
	uint16_t gyro_x;
	uint16_t gyro_y;
	uint16_t gyro_z;
	
	uint32_t pitch;
	uint32_t roll;
	uint32_t yaw;
}drvtIMU;


int drvt_imu(uint8_t cmd,drvtIMU* imu);

int drvt_infraredDetection(uint8_t* ifrd);

int drvt_infraredSend(uint16_t ifrt);

int drvt_infraredRecv(uint8_t* ifrr);

int drvt_laser(uint8_t num,uint8_t* laser_data);

int drvt_move(uint8_t speed,uint8_t yaw,uint8_t action);

int drvt_productInfo(drvtVersion* drvtInfo);

int drvt_init();

#endif