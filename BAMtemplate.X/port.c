#include "port.h"

#if MCU_TYPE == ATMEGA_168PA
volatile uint8_t *port_set_write[PORT_COUNT] = {&DDRB, &DDRC, &DDRD};
volatile uint8_t *port_write[PORT_COUNT] = {&PORTB, &PORTC, &PORTD};
volatile uint8_t *port_read[PORT_COUNT] = {&PINB, &PINC, &PIND};
#else
    #error "mcu type not implemented for port.c"
#endif
