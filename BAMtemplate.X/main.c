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


void external_interrupt_c(InterruptData interrupt_data){
    queue_append(INTERRUPT_DATA_GET(interrupt_data, 0, QueueHandle), PORT_READ(PORT_C));
}


int main(void){
    serial_init(4800);
    error_handler_configure_led(PORT_B, 0);
    error_set_handler(&error_handler_led_and_serial);
    
    ButtonStruct left_button_struct, right_button_struct;
    ButtonHandle left_button = BUTTON_HANDLE(left_button_struct);
    ButtonHandle right_button = BUTTON_HANDLE(right_button_struct);
    button_init(left_button, PORT_B, 1);
    button_init(right_button, PORT_B, 2);
    
    unsigned char re_queue_data[16];
    QueueStruct re_queue_struct;
    QueueHandle re_queue = QUEUE_HANDLE(re_queue_struct);
    queue_init(re_queue, re_queue_data, 16);
    
    RotaryEncoderStruct rotary_encoder_struct;
    RotaryEncoderHandle rotary_encoder = ROTARY_ENCODER_HANDLE(rotary_encoder_struct);
    rotary_encoder_init(rotary_encoder, 0, 1);
    
    unsigned char led_mask = (1 << 7);
    PORT_SET_WRITE(PORT_D) |= led_mask;
    port_ptr led_write_ptr = port_ptr_write(PORT_D);
    (void) led_write_ptr;
    
    INTERRUPT_DATA_CREATE(interrupt_data_c, 1);
    INTERRUPT_DATA_SET(interrupt_data_c, 0, re_queue);
    external_interrupt_set_function(PORT_C, &external_interrupt_c, interrupt_data_c);
    external_interrupt_enable_masked(PORT_C, 0x03);
    interrupt_enable();
    
    print_str("initialisation done\n");
    print_config();
    
    object_manager_print_info();
    print_long((unsigned int)object_manager_allocate(5));
    object_manager_print_info();
    print_long((unsigned int)object_manager_allocate(2));
    object_manager_print_info();

    while(1){
        rotary_encoder_update_with_queue(rotary_encoder, re_queue, 1);
    }
    return 0;
}
