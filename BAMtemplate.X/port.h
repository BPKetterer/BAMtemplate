/* 
 * File:   port.h
 * Author: Benni
 *
 * Created on September 29, 2024, 1:54 PM
 * 
 * This header manages the interaction (reading and writing) with the ports
 * of the MCU.
 */

#ifndef PORT_H
#define	PORT_H

#include "config.h"
#include <avr/io.h>

/*
 * Contains constants to reference the different ports of the selected hardware.
 * Has a PORT_UNDEFINED (= -1) constant. Actual ports start with 0.
 * Implementation further below.
 */
typedef enum port port;

/*
 * Evaluates to the number of ports.
 */
#define PORT_COUNT

/*
 * Evaluates to an lvalue of the register which controls the read/write
 * property of the passed port.
 */
#define PORT_SET_WRITE(port)

/*
 * Evaluates to an lvalue of the register which writes data to the the passed
 * port.
 */
#define PORT_WRITE(port)

/*
 * Evaluates to an lvalue of the register which reads data from the the passed
 * port.
 */
#define PORT_READ(port)

/*
 * Test if the passed port is valid.
 * @param   port    The port that is tested
 * @return  "true" if the port is a valid port
 */
uint8_t port_is_valid(port port);



/* -+-+--------------------------------+-+- */
/* -+-+- MCU SPECIFIC IMPLEMENTATION: -+-+- */
/* -+-+--VVVVVVVVVVVVVVVVVVVVVVVVVVVV--+-+- */

#undef PORT_COUNT
#undef PORT_SET_WRITE
#undef PORT_WRITE
#undef PORT_READ

#if MCU_TYPE == MCU_TYPE_ATMEGA_168PA

enum port {
    PORT_UNDEFINED = -1,
    PORT_B = 0,
    PORT_C,
    PORT_D,
};
#define PORT_COUNT 3
extern volatile uint8_t *port_set_write[PORT_COUNT];
extern volatile uint8_t *port_write[PORT_COUNT];
extern volatile uint8_t *port_read[PORT_COUNT];
#define PORT_SET_WRITE(port) (*(port_set_write[port]))
#define PORT_WRITE(port) (*(port_write[port]))
#define PORT_READ(port) (*(port_read[port]))

#else
#error "mcu type not implemented for port.h"
#endif

#endif	/* PORT_H */

