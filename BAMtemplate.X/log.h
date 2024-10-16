/* 
 * File:   log.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:54 PM
 * 
 * This header enables easy logging of data over the serial communication.
 */

#ifndef LOG_H
#define	LOG_H

#include "print.h"

/*
 * This prints the content of var as a string in the format:
 * <expression name/code> = <expression evaluated as a string>\n
 */
#define LOG_STR(var) \
    print_str(#var); \
    print_str(" = "); \
    print_str(var); \
    print_nl()

/*
 * This prints the content of var as a character in the format:
 * <expression name/code> = <expression evaluated as a character>\n
 */
#define LOG_CHAR(var) \
    print_str(#var); \
    print_str(" = "); \
    print_char(var); \
    print_nl()

/*
 * This prints the content of var as a signed integer with 64bits, in the format:
 * <expression name/code> = <expression evaluated as a signed integer with 64bits>\n
 */
#define LOG_INT64(var) \
    print_str(#var); \
    print_str(" = "); \
    print_int64(var); \
    print_nl()

/*
 * This prints the content of var as an unsigned integer with 64bits, in the format:
 * <expression name/code> = <expression evaluated as an unsigned integer with 64bits>\n
 */
#define LOG_UINT64(var) \
    print_str(#var); \
    print_str(" = "); \
    print_uint64(var); \
    print_nl()

/*
 * This prints the content of var as a float in the format:
 * <expression name/code> = <expression evaluated as a float>\n
 */
#define LOG_FLOAT(var) \
    print_str(#var); \
    print_str(" = "); \
    print_float(var); \
    print_nl()

/*
 * This prints the content of var as a hexadezimal byte in the format:
 * <expression name/code> = 0x<expression evaluated hexadecimal byte>\n
 */
#define LOG_HEX(var) \
    print_str(#var); \
    print_str(" = 0x"); \
    print_hex_byte(var); \
    print_nl()

/*
 * This prints the content of var as a binary byte in the format:
 * <expression name/code> = 0b<expression evaluated binary byte>\n
 */
#define LOG_BIN(var) \
    print_str(#var); \
    print_str(" = 0b"); \
    print_bin_byte(var); \
    print_nl()

/*
 * This prints the boolean interpretation of var in the format:
 * <expression name/code> = <true|false>\n
 */
#define LOG_BOOL(var) \
    print_str(#var); \
    print_str(" = "); \
    print_bool(var); \
    print_nl()

#endif	/* LOG_H */

