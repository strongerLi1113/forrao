/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: crc8.h
 * 
 * DESCRIPTION:   
 * 
 * Author: Jio
 * 
 * Date: 2017-4-27
 * 
 * History: 
 * 
 * E-mail: 385426564@qq.com
 * 
 ******************************************************************************/
#ifndef CRC8_H
#define CRC8_H

#include <stdint.h>


void init_crc8_tab(void);

uint8_t update_crc8( uint8_t crc, uint8_t c );

uint8_t calculate_crc8(uint8_t p[], unsigned int length);


#endif

