#include "rotary_encoder.h"


void rotary_encoder_init(RotaryEncoderHandle rotary_encoder, unsigned char pin_a, unsigned char pin_b){
    ERROR_ASSERT(rotary_encoder, ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL);
    ERROR_ASSERT(pin_a < 8, ERROR_CODE_ROTARY_ENCODER_ILLEGAL_PIN);
    ERROR_ASSERT(pin_b < 8, ERROR_CODE_ROTARY_ENCODER_ILLEGAL_PIN);
    ERROR_ASSERT(pin_a != pin_b, ERROR_CODE_ROTARY_ENCODER_SAME_PIN);
    rotary_encoder->status = 0;
    rotary_encoder->transitions[0] = 0;
    rotary_encoder->transitions[1] = 1 << pin_b;
    rotary_encoder->transitions[2] = (1 << pin_a) | (1 << pin_b);
    rotary_encoder->transitions[3] = 1 << pin_a;
    rotary_encoder->mask = (1 << pin_a) | (1 << pin_b);
    rotary_encoder->state_counter = 0;
}

void rotary_encoder_update(RotaryEncoderHandle rotary_encoder, unsigned char data){
    ERROR_ASSERT(rotary_encoder, ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL);
    unsigned char new_status;
    for(new_status = 0; rotary_encoder->transitions[new_status] != (data & rotary_encoder->mask); new_status++)
        ;
    signed char status_diff = ((unsigned char)(new_status - rotary_encoder->status + 5) & 0x3) - 1;
    rotary_encoder->status = new_status;
    if(status_diff != 2){
        rotary_encoder->state_counter += status_diff;
    }
}

void rotary_encoder_update_with_queue(RotaryEncoderHandle rotary_encoder, QueueHandle queue, unsigned char remove_used_elements){
    ERROR_ASSERT(rotary_encoder, ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL);
    ERROR_ASSERT(queue, ERROR_CODE_ROTARY_ENCODER_QUEUE_HANDLE_NULL);
    if(remove_used_elements){
        while(queue_size(queue)){
            rotary_encoder_update(rotary_encoder, queue_pop(queue));
        }
    } else {
        unsigned char idx;
        for(idx = 0; idx < queue_size(queue); idx++){
            rotary_encoder_update(rotary_encoder, queue_get(queue, idx));
        }
    }
}

signed char rotary_encoder_get_counter(RotaryEncoderHandle rotary_encoder){
    ERROR_ASSERT(rotary_encoder, ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL);
    return rotary_encoder->state_counter;
}

void rotary_encoder_reset_counter(RotaryEncoderHandle rotary_encoder){
    ERROR_ASSERT(rotary_encoder, ERROR_CODE_ROTARY_ENCODER_HANDLE_NULL);
    rotary_encoder->state_counter = 0;
}
