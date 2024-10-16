/* 
 * File:   timer_interrupt.h
 * Author: Benni
 *
 * Created on October 12, 2024, 7:56 PM
 */

#ifndef TIMER_INTERRUPT_H
#define	TIMER_INTERRUPT_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "error.h"

#if MCU_TYPE == MCU_TYPE_ATMEGA_168PA
typedef enum{
    TIMER_0 = 0,
    TIMER_1,
    TIMER_2,
    TIMER_COUNT = 3,
} timer;
#else
    #error "mcu type not implemented for timer_interrupt.h"
#endif

void timer_interrupt_init(void);

void timer_interrupt_set_period(timer timer, uint32_t us);

void timer_interrupt_set_function(timer timer, void (*function)(void *), void * interrupt_data);

void timer_interrupt_enable(timer timer);

void timer_interrupt_disable(timer timer);

void timer_interrupt_reset(timer timer);

uint32_t timer_interrupt_max_period_us(timer timer);

#endif	/* TIMER_INTERRUPT_H */

