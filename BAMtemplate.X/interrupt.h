/* 
 * File:   interrupt.h
 * Author: Benni
 *
 * Created on October 12, 2024, 2:05 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <avr/interrupt.h>

typedef void ** InterruptData;

void interrupt_enable(void);

void interrupt_disable(void);

#define INTERRUPT_DATA_CREATE(name, size) void* name[size]

#define INTERRUPT_DATA_SET(interrupt_data, idx, value) (interrupt_data)[idx] = (void*) &(value)

#define INTERRUPT_DATA_GET(interrupt_data, idx, type) (*(type*)(interrupt_data)[idx])

#endif	/* INTERRUPT_H */

