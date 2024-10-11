/* 
 * File:   pause.h
 * Author: Benni
 *
 * Created on October 11, 2024, 12:13 AM
 */

#ifndef PAUSE
#define	PAUSE

#include "config.h"
#define __DELAY_BACKWARD_COMPATIBLE__ /*to avoid error "__builtin_avr_delay_cycles expects a compile time integer constant" (this also occured when using the util/delay functions with constant expressions*/
#include <util/delay.h>

#ifndef F_CPU
#error "F_CPU not defined in config.h"
#endif

void pause_s(float s);

void pause_ms(float ms);

void pause_us(float us);

void pause_ns(float ns);

#endif	/* PAUSE */

