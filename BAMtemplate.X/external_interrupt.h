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

void external_interrupt_init(void);

void external_interrupt_enable(port port, uint8_t pin);

void external_interrupt_disable(port port, uint8_t pin);

void external_interrupt_enable_masked(port port, uint8_t mask);

void external_interrupt_disable_masked(port port, uint8_t mask);

void external_interrupt_set_function(port port, void (*function)(void *), void * interrupt_data);


#endif	/* EXTERNAL_INTERRUPT_H */

