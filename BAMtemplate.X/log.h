/* 
 * File:   log.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:54 PM
 */

#ifndef LOG_H
#define	LOG_H

#include "print.h"

#define LOG_STR(var) \
    print_str(#var); \
    print_str(" = "); \
    print_str(var); \
    print_nl()

#define LOG_CHAR(var) \
    print_str(#var); \
    print_str(" = "); \
    print_char(var); \
    print_nl()

#define LOG_INT64(var) \
    print_str(#var); \
    print_str(" = "); \
    print_int64(var); \
    print_nl()

#define LOG_UINT64(var) \
    print_str(#var); \
    print_str(" = "); \
    print_uint64(var); \
    print_nl()

#define LOG_FLOAT(var) \
    print_str(#var); \
    print_str(" = "); \
    print_float(var); \
    print_nl()

#define LOG_HEX(var) \
    print_str(#var); \
    print_str(" = 0x"); \
    print_hex_byte(var); \
    print_nl()

#define LOG_BIN(var) \
    print_str(#var); \
    print_str(" = 0b"); \
    print_bin_byte(var); \
    print_nl()

#define LOG_BOOL(var) \
    print_str(#var); \
    print_str(" = "); \
    print_bool(var); \
    print_nl()

#endif	/* LOG_H */

