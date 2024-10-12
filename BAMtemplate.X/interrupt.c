#include "interrupt.h"

void interrupt_enable(void){
    sei();
}

void interrupt_disable(void){
    cli();
}

