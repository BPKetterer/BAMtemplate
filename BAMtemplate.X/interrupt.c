#include "interrupt.h"


#if MCU_TYPE == MCU_TYPE_ATMEGA_168PA
void interrupt_global_enable(void){
    sei();
}

void interrupt_global_disable(void){
    cli();
}
#else
    #error "mcu type not implemented for interrupt.c"
#endif

