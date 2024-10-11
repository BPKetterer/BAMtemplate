#include "port.h"
#include "error.h"


unsigned char port_is_valid(port port){
    return port >= PORT_FIRST && port <= PORT_LAST;
}

#if MCU_TYPE == ATMEGA_168PA

port_ptr port_ptr_set_write(port port){
    ERROR_ASSERT(port >= PORT_FIRST && port <= PORT_LAST, ERROR_CODE_PORT_ILLEGAL_PORT);
    switch (port){
        case PORT_B:
            return &DDRB;
        case PORT_C:
            return &DDRC;
        case PORT_D:
            return &DDRD;
        /*default unreachable*/
    }
    return 0;
}

port_ptr port_ptr_write(port port){
    ERROR_ASSERT(port >= PORT_FIRST && port <= PORT_LAST, ERROR_CODE_PORT_ILLEGAL_PORT);
    switch (port){
        case PORT_B:
            return &PORTB;
        case PORT_C:
            return &PORTC;
        case PORT_D:
            return &PORTD;
        /*default unreachable*/
    }
    return 0;
}

port_ptr port_ptr_read(port port){
    ERROR_ASSERT(port >= PORT_FIRST && port <= PORT_LAST, ERROR_CODE_PORT_ILLEGAL_PORT);
    switch (port){
        case PORT_B:
            return &PINB;
        case PORT_C:
            return &PINC;
        case PORT_D:
            return &PIND;
        /*default unreachable*/
    }   
    return 0;
}

#else
    #error "mcu type not implemented for port.c"
#endif