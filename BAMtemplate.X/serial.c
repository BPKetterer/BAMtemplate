#include "serial.h"


#if MCU_TYPE == ATMEGA_168PA

#ifndef F_CPU
#error "F_CPU not defined/known in serial.c"
#endif

void serial_init(unsigned long baud_rate){
    /*Set baud rate */
    unsigned long ubrr = F_CPU / 16 / baud_rate - 1;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /*Enable receiver and transmitter */
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
    /* Set frame format: 8 data, 1 stop bit */
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}


void serial_send(unsigned char c){
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) )
        ;
    /* Put data into buffer, sends the data */
    UDR0 = c;
}


unsigned char serial_receive(void){
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
        ;
    /* Get and return received data from buffer */
    return UDR0;
}


unsigned char serial_try_receive(unsigned char *success){
    if(UCSR0A & (1<<RXC0)){
        *success = 1;
        return UDR0;
    } else {
        *success = 0;
        return 0;
    }
}

#else
    #error "mcu type not implemented for serial.c"
#endif

