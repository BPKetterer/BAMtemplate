#include "port.h"

uint8_t port_is_valid(port port) {
    return (port >= 0) && (port < PORT_COUNT);
}



/* -+-+--------------------------------+-+- */
/* -+-+- MCU SPECIFIC IMPLEMENTATION: -+-+- */
/* -+-+--VVVVVVVVVVVVVVVVVVVVVVVVVVVV--+-+- */

#if MCU_TYPE == MCU_TYPE_ATMEGA_168PA

volatile uint8_t *port_set_write[PORT_COUNT] = {&DDRB, &DDRC, &DDRD};
volatile uint8_t *port_write[PORT_COUNT] = {&PORTB, &PORTC, &PORTD};
volatile uint8_t *port_read[PORT_COUNT] = {&PINB, &PINC, &PIND};

#else
#error "mcu type not implemented for port.c"
#endif
