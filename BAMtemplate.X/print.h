/* 
 * File:   print.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:15 PM
 * 
 * This header uses the serial communication for easier output of different
 * data types.
 */

#ifndef PRINT_H
#define	PRINT_H

#include "serial.h"
#include "config.h"

/*
 * Sends a string over the serial communication.
 * @param   str     the string (char array) that gets sent
 */
void print_str(char *str);

/*
 * This sends a single character over the serial communication.
 * @param   c   the character that gets sent
 */
void print_char(char c);

/*
 * This sends a signed integer of 64 bits over the serial communication.
 * @param   n   the integer that gets sent
 */
void print_int64(int64_t n);

/*
 * This sends an unsigned integer of 64 bits over the serial communication.
 * @param   n   the integer that gets sent
 */
void print_uint64(uint64_t n);

/*
 * This sends a float over the serial communication.
 * @param   f   the float that gets sent
 */
void print_float(float f);

/*
 * This sends a byte as a hexadecimal over the serial communication.
 * @param   b   the byte that gets sent
 */
void print_hex_byte(uint8_t b);

/*
 * This sends a byte as a binary over the serial communication.
 * @param   b   the byte that gets sent
 */
void print_bin_byte(uint8_t b);

/*
 * This sends either "true" or "false" over the serial communication.
 * @param   b   the value that determines if true of false gets send
 */
void print_bool(uint8_t b);

/*
 * This send a new line character over the serial communication.
 */
void print_nl(void);

#endif	/* PRINT_H */

