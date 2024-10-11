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

void print_long(long n);

void print_ulong(unsigned long n);

void print_float(float f);

void print_hex_byte(unsigned char b);

void print_bin_byte(unsigned char b);

void print_bool(unsigned char b);

void print_nl(void);

void print_config(void);

#endif	/* PRINT_H */

