/* 
 * File:   serial.h
 * Author: Benni
 *
 * Created on September 28, 2024, 9:11 PM
 * 
 * This header manages the serial communication.
 * Before calling any of the other functions the serial_init function should be called.
 * When encountering problems, make sure that the F_CPU and correct Hardware is set in the config.h.
 */

#ifndef SERIAL_H
#define	SERIAL_H

#include "config.h"
#include <avr/io.h>

/*
 * Initialises the serial communication.
 * @param   baud_rate   The baud rate for the communication in Hz
 */
void serial_init(unsigned long baud_rate);

/*
 * Sends a character over the serial communication.
 * @param   c   The character that is send
 */
void serial_send(unsigned char c);

/*
 * Waits until a character is received over the serial communication.
 * @return  the received character
 */
unsigned char serial_receive(void);

/*
 * Attempts to received a character over the serial communication.
 * @param   success     When a character is received the value addressed is set to 1, otherwise it is set to 0
 * @return  the received character, or 0 if no character was received
 */
unsigned char serial_try_receive(unsigned char *success);

#endif	/* SERIAL_H */

