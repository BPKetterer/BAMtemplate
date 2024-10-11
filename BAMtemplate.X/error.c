#include "error.h"


void (*error_handler)(error_code) = &error_handler_serial;

port_ptr error_led_port_ptr = 0;
unsigned char error_led_pin;

void error_handle(error_code error_code) {
    error_handler(error_code);
}

void error_handler_serial(error_code error_code) {
    print_nl();
    print_str("ERROR: ");
    print_long(error_code);
    print_nl();
}

void error_handler_led(error_code error_code) {
    (void) error_code;
    #if ERROR_CHECK
    if(!error_led_port_ptr){
        error_handler_serial(ERROR_CODE_ERROR_UNDEFINED_LED);
    }
    #endif
    *error_led_port_ptr |= (unsigned char)1 << error_led_pin;
}

void error_handler_configure_led(port port, unsigned char pin) {
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_ERROR_ILLEGAL_LED_PORT);
    ERROR_ASSERT(pin < 8, ERROR_CODE_ERROR_ILLEGAL_LED_PIN);
    PORT_SET_WRITE(port) |= (unsigned char)1 << pin;
    error_led_port_ptr = port_ptr_write(port);
    error_led_pin = pin;
}

void error_handler_led_and_serial(error_code error_code) {
    error_handler_led(error_code);
    error_handler_serial(error_code);
}

void error_set_handler(void (*function)(error_code)) {
    error_handler = function;
}
