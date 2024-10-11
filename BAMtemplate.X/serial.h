/* 
 * File:   serial.h
 * Author: Benni
 *
 * Created on September 28, 2024, 9:11 PM
 */

#ifndef SERIAL_H
#define	SERIAL_H

#include "config.h"
#include <avr/io.h>

void serial_init(unsigned long baud_rate);

void serial_send(unsigned char c);

unsigned char serial_recieve(void);

unsigned char serial_try_recieve(unsigned char *success);

#endif	/* SERIAL_H */

