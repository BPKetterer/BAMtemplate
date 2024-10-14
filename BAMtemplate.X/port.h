/* 
 * File:   port.h
 * Author: Benni
 *
 * Created on September 29, 2024, 1:54 PM
 */

#ifndef PORT_H
#define	PORT_H

#include "config.h"
#include <avr/io.h>
#include "print.h"

#if MCU_TYPE == ATMEGA_168PA
typedef enum{
    PORT_UNDEFINED = -1,
    PORT_B = 0,
    PORT_C,
    PORT_D,
    PORT_COUNT = 3,
} port;
extern volatile uint8_t *port_set_write[PORT_COUNT];
extern volatile uint8_t *port_write[PORT_COUNT];
extern volatile uint8_t *port_read[PORT_COUNT];
#else
    #error "mcu type not implemented for port.h"
#endif


#define PORT_SET_WRITE(port) (*(port_set_write[port]))

#define PORT_WRITE(port) (*(port_write[port]))

#define PORT_READ(port) (*(port_read[port]))

#define PORT_IS_VALID(port) ((port) >= 0 && (port) < PORT_COUNT)

#endif	/* PORT_H */

