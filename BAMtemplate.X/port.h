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
/*error.h included in the body to avoid circular dependency*/

#if MCU_TYPE == ATMEGA_168PA
typedef enum{
    PORT_B = 0,
    PORT_C,
    PORT_D,
    PORT_FIRST = PORT_B,
    PORT_LAST = PORT_D
} port;
#else
    #error "mcu type not implemented for port.h"
#endif

typedef volatile unsigned char * port_ptr;


port_ptr port_ptr_set_write(port port);

port_ptr port_ptr_write(port port);

port_ptr port_ptr_read(port port);

unsigned char port_is_valid(port port);

#define PORT_SET_WRITE(port) (*port_ptr_set_write(port))

#define PORT_WRITE(port) (*port_ptr_write(port))

#define PORT_READ(port) (*port_ptr_read(port))

#define PORT_IS_VALID(port) ((port) >= PORT_FIRST && (port) <= PORT_LAST)

#endif	/* PORT_H */

