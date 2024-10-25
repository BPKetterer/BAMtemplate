/* 
 * File:   error.h
 * Author: Benni
 *
 * Created on October 2, 2024, 1:33 PM
 * 
 * This header allows easy handling and checking of errors
 */

#ifndef ERROR_H
#define	ERROR_H

#include "config.h"
#include "print.h"
#include "port.h"

/*
 * The different error types
 */
typedef enum{
    /*The object manager has not enough memory available: increase the OBJECT_MANAGER_SIZE in the config.h*/
    ERROR_CODE_OBJECT_MANAGER_NOT_ENOUGH_SPACE = 10,
    /*The led error handler is set and used, but the led is not configured: call the error_configure_handler_led function before the error_set_handler*/
    ERROR_CODE_ERROR_UNDEFINED_LED = 20,
    /*error_configure_handler_led was called with an illegal port*/
    ERROR_CODE_ERROR_ILLEGAL_LED_PORT = 21,
    /*error_configure_handler_led was called with an illegal pin*/
    ERROR_CODE_ERROR_ILLEGAL_LED_PIN = 22,
    /*An external interrupt was enabled which has not been given a function*/
    ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL = 40,
    /*A function in the external_interrupt.h was called with an illegal port*/
    ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT = 41,
    /*external_interrupt_enable was called with an illegal pin*/
    ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN = 42,
    /*A function in the button.h was called with a button (pointer) that is NULL*/
    ERROR_CODE_BUTTON_HANDLE_NULL = 50,
    /*button_create was called with an illegal port*/
    ERROR_CODE_BUTTON_ILLEGAL_PORT = 51,
    /*button_create was called with an illegal pin*/
    ERROR_CODE_BUTTON_ILLEGAL_PIN = 52,
    /*A function in the rotary_encoder.h was called with a rotary_encoder (pointer) that is NULL*/
    ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL = 60,
    /*rotary_encoder_create was called with an illegal pin*/
    ERROR_CODE_ROTARY_ENCODER_ILLEGAL_PIN = 61,
    /*rotary_encoder_create was called where both pins are the same*/
    ERROR_CODE_ROTARY_ENCODER_SAME_PIN = 62,
    /*rotary_encoder_update_with_queue was called with a queue (pointer) that is NULL*/
    ERROR_CODE_ROTARY_ENCODER_QUEUE_HANDLE_NULL = 63,
    /*A function in the queue.h was called with a queue (pointer) that is NULL*/
    ERROR_CODE_QUEUE_HANDLE_NULL = 70,
    /*queue_append was called on a full queue*/
    ERROR_CODE_QUEUE_FULL = 72,
    /*queue_pop was called on an empty queue*/
    ERROR_CODE_QUEUE_EMPTY = 73,
    /*queue_get was called on a queue which has less elements than the index*/
    ERROR_CODE_QUEUE_INVALID_IDX = 74,
    /*queue_create was called with a length of 0*/
    ERROR_CODE_QUEUE_INVALID_SIZE = 75,
    /*timer_interrupt_enable was called for a timer that did not get a (valid) via timer_interrupt_set_function*/
    ERROR_CODE_TIMER_INTERRUPT_FUNCTION_NULL = 80,
    /*A function in timer_interrupt_function.h was called with an unknown timer*/
    ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER = 81,
    /*timer_interrupt_set_period was called with a us value that is too large for that timer*/
    ERROR_CODE_TIMER_INTERRUPT_OVERFLOW = 82,
} error_code;

/*
 * Calls the configured error handler.
 * @param   error_code  The code of the error that occurred
 */
void error_handle(error_code error_code);

/*
 * Configures the led for the provided led error handler.
 * @param   port    The port of the led
 * @param   pin     The pin index of the led on that port
 */
void error_configure_handler_led(port port, uint8_t pin);

/*
 * Configure which error handler should be used. This can also be an external
 * function.
 * @param   function    The function that is called when an error occurred
 */
void error_set_handler(void (*function)(error_code));

/*
 * This handler sends a message over the serial communication with the error
 * code.
 * @param   error_code  The code of the error that occurred
 */
void error_handler_serial(error_code error_code);

/*
 * This handler enables an led when an error occurred
 * @param   error_code  Unused
 */
void error_handler_led(error_code error_code);

/*
 * This handler calls both the led and the serial error handler.
 * @param   error_code  The code of the error that occurred
 */
void error_handler_led_and_serial(error_code error_code);

/*
 * This macro (when ERROR_CHECK is enabled) checks an expression. If the
 * expression is false the error_handle function is called with the passed
 * error_code.
 * @param   condition   The expression that is checked
 * @parm    error_code  The code of the error, if the condition is not met
 */
#if ERROR_CHECK
#define ERROR_ASSERT(condition, error_code) ((condition) ? ((void)0) : error_handle(error_code))
#else
#define ERROR_ASSERT(condition, error_code) ((void)0)
#endif

#endif	/* ERROR_H */

