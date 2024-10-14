#include "external_interrupt.h"

void (*external_interrupt_functions[PORT_COUNT])(void *) = {};
void * external_interrupt_data[PORT_COUNT] = {};

#define EXTERNAL_INTERRUPT_CALL_FUNCTION(port) (*external_interrupt_functions[port])(external_interrupt_data[port])

void external_interrupt_enable(port port, uint8_t pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_enable_masked(port, (uint8_t)1 << pin);
}

void external_interrupt_disable(port port, uint8_t pin){
    ERROR_ASSERT(pin < 8, ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN);
    external_interrupt_disable_masked(port, (uint8_t)1 << pin);
}

void external_interrupt_set_function(port port, void (*function)(void *), void * interrupt_data){
    ERROR_ASSERT(PORT_IS_VALID(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    external_interrupt_functions[port] = function;
    external_interrupt_data[port] = interrupt_data;
}

#if MCU_TYPE == ATMEGA_168PA

volatile uint8_t *external_interrupt_mask_byte[PORT_COUNT] = {&PCMSK0, &PCMSK1, &PCMSK2};

ISR(PCINT0_vect){
    EXTERNAL_INTERRUPT_CALL_FUNCTION(PORT_B);
}

ISR(PCINT1_vect){
    EXTERNAL_INTERRUPT_CALL_FUNCTION(PORT_C);
}

ISR(PCINT2_vect){
    EXTERNAL_INTERRUPT_CALL_FUNCTION(PORT_D);
}

void external_interrupt_init(void){}

void external_interrupt_enable_masked(port port, uint8_t mask){
    ERROR_ASSERT(PORT_IS_VALID(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    ERROR_ASSERT(external_interrupt_functions[port], ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL);
    PCICR |= (uint8_t)(1 << port);
    *external_interrupt_mask_byte[port] |= mask;
}

void external_interrupt_disable_masked(port port, uint8_t mask){
    ERROR_ASSERT(PORT_IS_VALID(port), ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT);
    *external_interrupt_mask_byte[port] &= ~mask;
    if(*external_interrupt_mask_byte[port] == 0){
        PCICR &= ~(uint8_t)(1 << port);
    }
}

#else
    #error "mcu type not implemented for external_interrupt.c"
#endif