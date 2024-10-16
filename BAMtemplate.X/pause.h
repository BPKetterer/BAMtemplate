/* 
 * File:   pause.h
 * Author: Benni
 *
 * Created on October 11, 2024, 12:13 AM
 */

#ifndef PAUSE_H
#define	PAUSE_H

#include "config.h"
#define __DELAY_BACKWARD_COMPATIBLE__ /*to avoid error "__builtin_avr_delay_cycles expects a compile time integer constant" (this also occured when using the util/delay functions with constant expressions*/
#include <util/delay.h>

void pause_s(float s);

void pause_ms(float ms);

void pause_us(float us);

void pause_ns(float ns);

#endif	/* PAUSE_H */

