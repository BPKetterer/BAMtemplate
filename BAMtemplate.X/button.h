/* 
 * File:   button.h
 * Author: Benni
 *
 * Created on October 2, 2024, 10:24 AM
 */

#ifndef BUTTON_H
#define	BUTTON_H


#include "port.h"
#include "error.h"

typedef struct {
    port_ptr port_ptr_read;
    unsigned char pin;
    signed char status;
} ButtonStruct;

typedef ButtonStruct* ButtonHandle;

void button_init(ButtonHandle button, port port, unsigned char pin);

void button_update(ButtonHandle button);

unsigned char button_is_pressed(ButtonHandle button);

unsigned char button_duration(ButtonHandle button);

#define BUTTON_HANDLE(button_struct) (&(button_struct))

#endif	/* BUTTON_H */

