/* 
 * File:   external_interrupt.h
 * Author: Benni
 *
 * Created on October 2, 2024, 12:49 PM
 * 
 * This header allows easy usage of the external interrupts
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "port.h"
#include "error.h"

/*
 * Initiates some stuff for the external interrupts
 */
void external_interrupt_init(void);

/*
 * Sets the function that is called by the port, when an external interrupt is
 * triggered.
 * @param   port            The port for which the function is used
 * @param   funciton        The function that is called when the interrupt is
 *                          triggered
 * @param   interrupt_data  A pointer to data that is passed to the interrupt
 *                          function
 */
void external_interrupt_set_function(port port, void (*function)(void *), void * interrupt_data);

/*
 * Enables an external interrupt of a specific pin.
 * @param   port    The port of the pin
 * @param   pin     The pin
 */
void external_interrupt_enable(port port, uint8_t pin);

/*
 * Disables an external interrupt of a specific pin.
 * @param   port    The port of the pin
 * @param   pin     The pin
 */
void external_interrupt_disable(port port, uint8_t pin);

/*
 * Enables external interrupts for a port with a pin mask.
 * @param   port    The port for which the mask is
 * @param   mask    The mask of the pins that are enabled
 */
void external_interrupt_enable_masked(port port, uint8_t mask);

/*
 * Disables external interrupts for a port with a pin mask.
 * @param   port    The port for which the mask is
 * @param   mask    The mask of the pins that are disabled
 */
void external_interrupt_disable_masked(port port, uint8_t mask);

#endif	/* EXTERNAL_INTERRUPT_H */

