/* 
 * File:   button.h
 * Author: Benni
 *
 * Created on October 2, 2024, 10:24 AM
 * 
 * This header allows for easy usage of Buttons.
 */

#ifndef BUTTON_H
#define	BUTTON_H


#include "port.h"
#include "error.h"
#include "object_manager.h"

/*
 * The struct that saves the internal information for a button.
 */
struct button {
    port port;
    uint8_t pin;
    int8_t status;
};

/*
 * The handle type which is passed to the button functions. Since this is a
 * pointer it can be passed to other functions and still reference the same
 * object.
 */
typedef struct button * Button;

/*
 * Creates a button.
 * @param   port    The port, where the button is connected to
 * @param   pin     The pin of the button on the specified port
 * @return  the handle for the button
 */
Button button_create(port port, uint8_t pin);

/*
 * Checks the input and updates the status of the button.
 * @param   button  The button that is updated
 */
void button_update(Button button);

/*
 * Returns if a button is currently pressed.
 * @param   button  The button that is checked
 * @return  A non-zero value, when the button is pressed
 */
uint8_t button_is_pressed(Button button);

/*
 * Returns if a button was pressed since the last cycle.
 * @param   button  The button that is checked
 * @return  A non-zero value, when the button was pressed since the last cycle
 */
uint8_t button_just_pressed(Button button);

/*
 * Returns if a button was released since the last cycle.
 * @param   button  The button that is checked
 * @return  A non-zero value, when the button was released since the last cycle
 */
uint8_t button_just_released(Button button);

/*
 * Returns how long a button is in the current state.
 * @param   button  The button that is checked
 * @return  The amount of updates called where the button did not change its
 *          state (caps at 127)
 */
uint8_t button_duration(Button button);

#endif	/* BUTTON_H */

