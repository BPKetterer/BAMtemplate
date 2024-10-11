#include "pause.h"



#if ATMEGA_168PA

#define MAX_DELAY_MS (262 * 1000000 / F_CPU)
#define MAX_DELAY_US (768 * 1000000 / F_CPU)

void pause_s(float s){
    pause_ms(s * 1000);
}

void pause_ms(float ms){
    while(ms > MAX_DELAY_MS){
        _delay_ms(MAX_DELAY_MS);
        ms -= MAX_DELAY_MS;
    }
    _delay_ms(ms);
}

void pause_us(float us){
    while(us > MAX_DELAY_US){
        _delay_us(MAX_DELAY_US);
        us -= MAX_DELAY_US;
    }
    _delay_us(us);
}

void pause_ns(float ns){
    pause_ms(ns / 1000);
}


#else
    #error "no known hardware in port.c"
#endif