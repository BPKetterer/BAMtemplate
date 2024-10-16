/* 
 * File:   error.h
 * Author: Benni
 *
 * Created on October 2, 2024, 1:33 PM
 */

#ifndef ERROR_H
#define	ERROR_H

#include "config.h"
#include "print.h"
#include "port.h"

typedef enum{
    ERROR_HANDLER_NONE,
    ERROR_HANDLER_SERIAL,
    ERROR_HANDLER_LED,
    ERROR_HANDLER_LED_AND_SERIAL,
} basic_error_handler;

typedef enum{
    ERROR_CODE_OBJECT_MANAGER_NOT_ENOUGH_SPACE = 10,
    ERROR_CODE_ERROR_UNDEFINED_LED = 20,
    ERROR_CODE_ERROR_ILLEGAL_LED_PORT = 21,
    ERROR_CODE_ERROR_ILLEGAL_LED_PIN = 22,
    ERROR_CODE_PORT_ILLEGAL_PORT = 30,
    ERROR_CODE_EXTERNAL_INTERRUPT_FUNCTION_NULL = 40,
    ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PORT = 41,
    ERROR_CODE_EXTERNAL_INTERRUPT_ILLEGAL_PIN = 42,
    ERROR_CODE_BUTTON_HANDLE_NULL = 50,
    ERROR_CODE_BUTTON_ILLEGAL_PORT = 51,
    ERROR_CODE_BUTTON_ILLEGAL_PIN = 52,
    ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL = 60,
    ERROR_CODE_ROTARY_ENCODER_ILLEGAL_PIN = 61,
    ERROR_CODE_ROTARY_ENCODER_SAME_PIN = 62,
    ERROR_CODE_ROTARY_ENCODER_QUEUE_HANDLE_NULL = 63,
    ERROR_CODE_QUEUE_HANDLE_NULL = 70,
    ERROR_CODE_QUEUE_FULL = 72,
    ERROR_CODE_QUEUE_EMPTY = 73,
    ERROR_CODE_QUEUE_INVALID_IDX = 74,
    ERROR_CODE_QUEUE_INVALID_SIZE = 75,
    ERROR_CODE_TIMER_INTERRUPT_FUNCTION_NULL = 80,
    ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER = 81,
    ERROR_CODE_TIMER_INTERRUPT_OVERFLOW = 82,
} error_code;

void error_handle(error_code error_code);

void error_handler_configure_led(port port, uint8_t pin);

void error_set_basic_handler(basic_error_handler handler);

void error_set_custom_handler(void (*function)(error_code));

#if ERROR_CHECK
#define ERROR_ASSERT(condition, error_code) ((condition) ? ((void)0) : error_handle(error_code))
#else
#define ERROR_ASSERT(condition, error_code) ((void)0)
#endif

#endif	/* ERROR_H */

