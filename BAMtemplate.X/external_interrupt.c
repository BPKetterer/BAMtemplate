#include "external_interrupt.h"


void external_interrupt_enable(port port, uint8_t pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_enable_masked(port, (uint8_t)1 << pin);
}

void external_interrupt_disable(port port, uint8_t pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_disable_masked(port, (uint8_t)1 << pin);
}


#if MCU_TYPE == ATMEGA_168PA

void (*external_interrupt_b_function)(void *) = 0;
void (*external_interrupt_c_function)(void *) = 0;
void (*external_interrupt_d_function)(void *) = 0;

void * external_interrupt_b_data = 0;
void * external_interrupt_c_data = 0;
void * external_interrupt_d_data = 0;

ISR(PCINT0_vect){
    external_interrupt_b_function(external_interrupt_b_data);
}

ISR(PCINT1_vect){
    external_interrupt_c_function(external_interrupt_c_data);
}

ISR(PCINT2_vect){
    external_interrupt_d_function(external_interrupt_d_data);
}

void external_interrupt_enable_masked(port port, uint8_t mask){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            ERROR_ASSERT(external_interrupt_b_function, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE0);
            PCMSK0 |= mask;
            break;
        case PORT_C:
            ERROR_ASSERT(external_interrupt_c_function, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE1);
            PCMSK1 |= mask;
            break;
        case PORT_D:
            ERROR_ASSERT(external_interrupt_d_function, ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
            PCICR |= (1 << PCIE2);
            PCMSK2 |= mask;
            break;
        /*default unreachable*/
    }
}

void external_interrupt_disable_masked(port port, uint8_t mask){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            PCMSK0 &= ~mask;
            if(PCMSK0 == 0){
                PCICR &= ~((uint8_t)1 << PCIE0);
            }
            break;
        case PORT_C:
            PCMSK1 &= ~mask;
            if(PCMSK1 == 0){
                PCICR &= ~((uint8_t)1 << PCIE1);
            }
            break;
        case PORT_D:
            PCMSK2 &= ~mask;
            if(PCMSK2 == 0){
                PCICR &= ~((uint8_t)1 << PCIE2);
            }
            break;
        /*default unreachable*/
    }
}

void external_interrupt_set_function(port port, void (*function)(void *), void * interrupt_data){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    switch(port){
        case PORT_B:
            external_interrupt_b_function = function;
            external_interrupt_b_data = interrupt_data;
            break;
        case PORT_C:
            external_interrupt_c_function = function;
            external_interrupt_c_data = interrupt_data;
            break;
        case PORT_D:
            external_interrupt_d_function = function;
            external_interrupt_d_data = interrupt_data;
            break;
        /*default unreachable*/
    }
}

#else
    #error "mcu type not implemented for external_interrupt.c"
#endif