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


void external_interrupt_c(void * interrupt_data){
    queue_append((Queue) interrupt_data, PORT_READ(PORT_C));
}


int main(void){
    serial_init(4800);
    error_handler_configure_led(PORT_B, 0);
    error_set_handler(&error_handler_led_and_serial);
    
    Button left_button = button_create(PORT_B, 1);
    Button right_button = button_create(PORT_B, 2);
    
    Queue re_queue = queue_create(30);
    RotaryEncoder rotary_encoder = rotary_encoder_create(0, 1);
    
    unsigned char led_mask = (1 << 7);
    PORT_SET_WRITE(PORT_D) |= led_mask;
    port_ptr led_write_ptr = port_ptr_write(PORT_D);
    (void) led_write_ptr;
    
    external_interrupt_set_function(PORT_C, &external_interrupt_c, (void *) re_queue);
    external_interrupt_enable_masked(PORT_C, 0x03);
    interrupt_global_enable();
    
    print_str("initialisation done\n");
    print_config();
    object_manager_print_info();

    while(1){
        button_update(left_button);
        button_update(right_button);
        rotary_encoder_update_with_queue(rotary_encoder, re_queue, 1);
        
        print_bool(button_is_pressed(left_button));
        print_str(" ");
        print_long(button_duration(left_button));
        print_str("   ");
        print_bool(button_is_pressed(right_button));
        print_str(" ");
        print_long(button_duration(right_button));
        print_str("   ");
        print_long(rotary_encoder_get_counter(rotary_encoder));
        print_nl();
    }
    return 0;
}
