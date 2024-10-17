/*
 * File:   main.c
 * Author: Benni
 *
 * Created on September 28, 2024, 2:46 PM
 */

#include "serial.h"
#include "error.h"
#include "print.h"
#include "log.h"
#include "port.h"
#include "button.h"
#include "external_interrupt.h"
#include "queue.h"
#include "rotary_encoder.h"
#include "pause.h"
#include "interrupt.h"
#include "object_manager.h"
#include "timer_interrupt.h"


void external_interrupt_c(void * interrupt_data){
    queue_try_append((Queue) interrupt_data, PORT_READ(PORT_C));
}

void timer_interrupt(void * interrupt_data){
    (void) interrupt_data;
    PORT_WRITE(PORT_D) ^= 1 << 7;
}

int main(void){
    serial_init(4800);
    error_handler_configure_led(PORT_B, 0);
    error_set_basic_handler(ERROR_HANDLER_LED_AND_SERIAL);
    print_str("\n\n\n");
    
    Button left_button = button_create(PORT_B, 1);
    Button right_button = button_create(PORT_B, 2);

    Queue re_queue = queue_create(30);
    RotaryEncoder rotary_encoder = rotary_encoder_create(0, 1);
    
    PORT_SET_WRITE(PORT_D) |= 1 << 7;
    
    external_interrupt_init();
    external_interrupt_set_function(PORT_C, &external_interrupt_c, (void *) re_queue);
    external_interrupt_enable_masked(PORT_C, 0x03);
    
    timer_interrupt_init();
    timer_interrupt_set_function(TIMER_1, &timer_interrupt, 0);
    timer_interrupt_set_period(TIMER_1, 10000UL * 1000UL);
    timer_interrupt_enable(TIMER_1);

    interrupt_global_enable();
    
    object_manager_print_info();
    
    while(1){
        button_update(left_button);
        button_update(right_button);
        rotary_encoder_update_with_queue(rotary_encoder, re_queue, 1);
        
        print_bool(button_is_pressed(left_button));
        print_str(" ");
        print_int64(button_duration(left_button));
        print_str("   ");
        print_bool(button_is_pressed(right_button));
        print_str(" ");
        print_int64(button_duration(right_button));
        print_str("   ");
        print_int64(rotary_encoder_get_counter(rotary_encoder));
        print_nl();
    }
    return 0;
}
