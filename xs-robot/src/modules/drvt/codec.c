/***************************************************************************
** Copyright: 2004 浙江向上软件有限公司 Copyright (c)

** File Name:  Y:\source\xs-robot\src\modules\drvt\codec.c 

** DESCRIPTION: 

** Author: lijun  

** Data: 2017-10-19

** Email: q19881113@126.com 

** History: 

***************************************************************************/

#include "codec.h"

int encode_unsigned8(
	 uint8_t * buffer,
	 uint8_t value)
{
	buffer[0] = value;

	return 1;
}
 
 int decode_unsigned8(
	 uint8_t * buffer,
	 uint8_t * value)
 {
 	if(value)
		*value = buffer[0];

	return 1;
 }


 int encode_unsigned16(
	 uint8_t * buffer,
	 uint16_t value)
 {
	 buffer[0] = (uint8_t) ((value & 0xff00) >> 8);
	 buffer[1] = (uint8_t) (value & 0x00ff);
 
	 return 2;
 }
 
 int decode_unsigned16(
	 uint8_t * buffer,
	 uint16_t * value)
 {
	 if (value) {
		 *value = (uint16_t) ((((uint16_t) buffer[0]) << 8) & 0xff00);
		 *value |= ((uint16_t) (((uint16_t) buffer[1]) & 0x00ff));
	 }
 
	 return 2;
 }


 
 int encode_unsigned24(
	 uint8_t * buffer,
	 uint32_t value)
 {
	 buffer[0] = (uint8_t) ((value & 0xff0000) >> 16);
	 buffer[1] = (uint8_t) ((value & 0x00ff00) >> 8);
	 buffer[2] = (uint8_t) (value & 0x0000ff);
 
	 return 3;
 }
 
 int decode_unsigned24(
	 uint8_t * buffer,
	 uint32_t * value)
 {
	 if (value) {
		 *value = ((uint32_t) ((((uint32_t) buffer[0]) << 16) & 0x00ff0000));
		 *value |= (uint32_t) ((((uint32_t) buffer[1]) << 8) & 0x0000ff00);
		 *value |= ((uint32_t) (((uint32_t) buffer[2]) & 0x000000ff));
	 }
 
	 return 3;
 }


 
 
 int encode_unsigned32(
	 uint8_t * buffer,
	 uint32_t value)
 {
	 buffer[0] = (uint8_t) ((value & 0xff000000) >> 24);
	 buffer[1] = (uint8_t) ((value & 0x00ff0000) >> 16);
	 buffer[2] = (uint8_t) ((value & 0x0000ff00) >> 8);
	 buffer[3] = (uint8_t) (value & 0x000000ff);
 
	 return 4;
 }
 
 int decode_unsigned32(
	 uint8_t * buffer,
	 uint32_t * value)
 {
	 if (value) {
		 *value = ((uint32_t) ((((uint32_t) buffer[0]) << 24) & 0xff000000));
		 *value |= ((uint32_t) ((((uint32_t) buffer[1]) << 16) & 0x00ff0000));
		 *value |= ((uint32_t) ((((uint32_t) buffer[2]) << 8) & 0x0000ff00));
		 *value |= ((uint32_t) (((uint32_t) buffer[3]) & 0x000000ff));
	 }
 
	 return 4;
 }


 
  int decode_signed32(
	 uint8_t * buffer,
	 int32_t * value)
  {
  	 if (value) {
		 *value = ((int32_t) ((((int32_t) buffer[0]) << 24) & 0xff000000));
		 *value |= ((int32_t) ((((int32_t) buffer[1]) << 16) & 0x00ff0000));
		 *value |= ((int32_t) ((((int32_t) buffer[2]) << 8) & 0x0000ff00));
		 *value |= ((int32_t) (((int32_t) buffer[3]) & 0x000000ff));
	 }
 
	 return 4;
  }


 int encode_octet_string(
    uint8_t * buffer,
    uint8_t * octet_string,  uint32_t octet_string_len)
{
    int i = 0;  /* loop counter */

    if (octet_string) {
        for (i = 0; i < octet_string_len; i++) {
            buffer[i] = octet_string[i];
        }
    }

    return octet_string_len;
}


 int decode_octet_string(
    uint8_t * buffer,
    uint8_t * octet_string,  uint32_t octet_string_len)
{
    int i = 0;  /* loop counter */

    if (octet_string) {
        for (i = 0; i < octet_string_len; i++) {
            octet_string[i] = buffer[i];
        }
    }

    return octet_string_len;
}




