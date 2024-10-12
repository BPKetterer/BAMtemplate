/* 
 * File:   interrupt.h
 * Author: Benni
 *
 * Created on October 12, 2024, 2:05 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <avr/interrupt.h>
#include "config.h"

void interrupt_global_enable(void);

void interrupt_global_disable(void);

#endif	/* INTERRUPT_H */

