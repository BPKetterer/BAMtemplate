#include "error.h"

void (*error_handler)(error_code) = &error_handler_serial;

port error_led_port = PORT_UNDEFINED;
uint8_t error_led_pin = 0;

void error_handle(error_code error_code) {
    error_handler(error_code);
}

void error_set_handler(void (*function)(error_code)){
    error_handler = function;
}

void error_configure_handler_led(port port, uint8_t pin) {
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_ERROR_ILLEGAL_LED_PORT);
    ERROR_ASSERT(pin < 8, ERROR_CODE_ERROR_ILLEGAL_LED_PIN);
    PORT_SET_WRITE(port) |= (uint8_t)1 << pin;
    error_led_port = port;
    error_led_pin = pin;
}

void error_handler_serial(error_code error_code) {
    print_nl();
    print_str("ERROR: ");
    print_int64(error_code);
    print_nl();
}

void error_handler_led(error_code error_code) {
    (void) error_code;
    #if ERROR_CHECK
    if(error_led_port == PORT_UNDEFINED){
        error_handler_serial(ERROR_CODE_ERROR_UNDEFINED_LED);
    }
    #endif
    PORT_WRITE(error_led_port) |= (uint8_t)1 << error_led_pin;
}

void error_handler_led_and_serial(error_code error_code) {
    error_handler_led(error_code);
    error_handler_serial(error_code);
}
