/* 
 * File:   print.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:15 PM
 */

#ifndef PRINT_H
#define	PRINT_H

#include "serial.h"
#include "config.h"

void print_str(char *str);

void print_char(char c);

void print_int64(int64_t n);

void print_uint64(uint64_t n);

void print_float(float f);

void print_hex_byte(uint8_t b);

void print_bin_byte(uint8_t b);

void print_bool(uint8_t b);

void print_nl(void);

void print_config(void);

#endif	/* PRINT_H */

