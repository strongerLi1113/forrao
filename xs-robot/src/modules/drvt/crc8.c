/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: crc8.c
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
#include <stdint.h>
#include "crc8.h"

#define     P_8         0xD5


uint8_t crc8_table[256];


void init_crc8_normal_tab(uint8_t table[], uint8_t polynom)
{
  int i, j;
  uint8_t crc;

  for (i=0; i<256; i++)
  {
	  crc = (uint8_t) i;

	  for (j=0; j<8; j++)
	  {
	    if (crc & 0x80) 
				crc = (crc << 1) ^ polynom;
	    else            
				crc <<= 1;
	  }
		
	  table[i] = crc;
  }
}



void init_crc8_tab(void)
{
  init_crc8_normal_tab(crc8_table, P_8);
  	int i;
	//printf("\n");
	//for(i=0;i<256;i++)
	//	printf("%02x ",crc8_table[i]);
	//printf("\n");
}


uint8_t update_crc8( uint8_t crc, uint8_t c )
{
	return (crc8_table[crc ^ c]);
}


uint8_t calculate_crc8(uint8_t p[], unsigned int length)
{
	uint8_t crc;
	unsigned int i;

  crc = 0;

  for (i=0; i < length; i++)
  {
    crc = update_crc8(crc,p[i]);
  }
	
  return crc;
}



