/******************************************************************************
 * Copyright 2013 杭州笃远智能科技有限公司 Co.,Ltd.
 * 
 * File Name: codec.h
 * 
 * DESCRIPTION:   
 * 
 * Author: Jio
 * 
 * Date: 2016-8-09
 * 
 * History: 
 * 
 * E-mail: 385426564@qq.com
 * 
 ******************************************************************************/
#ifndef CODEC_H
#define CODEC_H

#include <stdint.h>
//#include "ISBaseTypes.h"
	 
 int encode_unsigned8(
	 uint8_t * buffer,
	 uint8_t value);
 
 int decode_unsigned8(
	 uint8_t * buffer,
	 uint8_t * value);
 
 /* unsigned value encoding and decoding */
 int encode_unsigned16(
	 uint8_t * buffer,
	 uint16_t value);
 int decode_unsigned16(
	 uint8_t * buffer,
	 uint16_t * value);
 
 
 int encode_unsigned24(
	 uint8_t * buffer,
	 uint32_t value);
 int decode_unsigned24(
	 uint8_t * buffer,
	 uint32_t * value);
 
 
 
 int encode_unsigned32(
	 uint8_t * buffer,
	 uint32_t value);
 int decode_unsigned32(
	 uint8_t * buffer,
	 uint32_t * value);


  int decode_signed32(
	 uint8_t * buffer,
	 int32_t * value);
 
 
 int encode_octet_string(
	uint8_t * buffer,
	uint8_t * octet_string,  uint32_t octet_string_len);
	 
 int decode_octet_string(
	uint8_t * buffer,
	uint8_t * octet_string,  uint32_t octet_string_len);

	 
#endif


