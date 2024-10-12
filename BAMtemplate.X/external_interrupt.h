/* 
 * File:   external_interrupt.h
 * Author: Benni
 *
 * Created on October 2, 2024, 12:49 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "port.h"
#include "error.h"
#include "interrupt.h"

void external_interrupt_enable(port port, unsigned char pin);

void external_interrupt_disable(port port, unsigned char pin);

void external_interrupt_enable_masked(port port, unsigned char mask);

void external_interrupt_disable_masked(port port, unsigned char mask);

void external_interrupt_set_function(port port, void (*function)(InterruptData), InterruptData interrupt_data);


#endif	/* EXTERNAL_INTERRUPT_H */

