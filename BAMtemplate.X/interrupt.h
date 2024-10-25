/* 
 * File:   interrupt.h
 * Author: Benni
 *
 * Created on October 12, 2024, 2:05 PM
 * 
 * This header manages the global en-/dis-ablement of interrupts
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <avr/interrupt.h>
#include "config.h"

/*
 * Allows all interrupts.
 */
void interrupt_global_enable(void);

/*
 * Prevents all interrupts.
 */
void interrupt_global_disable(void);

#endif	/* INTERRUPT_H */

