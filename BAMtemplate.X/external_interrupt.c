#include "external_interrupt.h"


void external_interrupt_enable(port port, unsigned char pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_enable_masked(port, (unsigned char)1 << pin);
}

void external_interrupt_disable(port port, unsigned char pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_disable_masked(port, (unsigned char)1 << pin);
}


#if MCU_TYPE == ATMEGA_168PA

void (*interrupt_b)(void) = 0;
void (*interrupt_c)(void) = 0;
void (*interrupt_d)(void) = 0;

ISR(PCINT0_vect){
    interrupt_b();
}

ISR(PCINT1_vect){
    interrupt_c();
}

ISR(PCINT2_vect){
    interrupt_d();
}

void external_interrupt_enable_masked(port port, unsigned char mask){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            ERROR_ASSERT(interrupt_b, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE0);
            PCMSK0 |= mask;
            break;
        case PORT_C:
            ERROR_ASSERT(interrupt_c, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE1);
            PCMSK1 |= mask;
            break;
        case PORT_D:
            ERROR_ASSERT(interrupt_d, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE2);
            PCMSK2 |= mask;
            break;
        /*default unreachable*/
    }
}

void external_interrupt_disable_masked(port port, unsigned char mask){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            PCMSK0 &= ~mask;
            if(PCMSK0 == 0){
                PCICR &= ~((unsigned char)1 << PCIE0);
            }
            break;
        case PORT_C:
            PCMSK1 &= ~mask;
            if(PCMSK1 == 0){
                PCICR &= ~((unsigned char)1 << PCIE1);
            }
            break;
        case PORT_D:
            PCMSK2 &= ~mask;
            if(PCMSK2 == 0){
                PCICR &= ~((unsigned char)1 << PCIE2);
            }
            break;
        /*default unreachable*/
    }
}

void external_interrupt_set_function(port port, void (*function)(void)){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            interrupt_b = function;
            break;
        case PORT_C:
            interrupt_c = function;
            break;
        case PORT_D:
            interrupt_d = function;
            break;
        /*default unreachable*/
    }
}

#else
    #error "mcu type not implemented for external_interrupt.c"
#endif