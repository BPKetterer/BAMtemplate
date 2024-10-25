/* 
 * File:   pause.h
 * Author: Benni
 *
 * Created on October 11, 2024, 12:13 AM
 * 
 * This header provides function for pausing/delaying
 */

#ifndef PAUSE_H
#define	PAUSE_H

#include "config.h"
#define __DELAY_BACKWARD_COMPATIBLE__ /*to avoid error "__builtin_avr_delay_cycles expects a compile time integer constant" (this also occured when using the util/delay functions with constant expressions*/
#include <util/delay.h>

/*
 * Pauses the execution by the given amount in seconds.
 * @param   s   The (minimum) duration of the pause in seconds
 */
void pause_s(float s);

/*
 * Pauses the execution by the given amount in milliseconds.
 * @param   ms  The (minimum) duration of the pause in milliseconds
 */
void pause_ms(float ms);

/*
 * Pauses the execution by the given amount in microseconds.
 * @param   us  The (minimum) duration of the pause in microseconds
 */
void pause_us(float us);

/*
 * Pauses the execution by the given amount in nanoseconds.
 * @param   ns  The (minimum) duration of the pause in nanoseconds
 */
void pause_ns(float ns);

#endif	/* PAUSE_H */

