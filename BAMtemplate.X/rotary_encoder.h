/* 
 * File:   rotary_encoder.h
 * Author: Benni
 *
 * Created on October 6, 2024, 4:05 PM
 */

#ifndef ROTARY_ENCODER_H
#define	ROTARY_ENCODER_H

#include "queue.h"
#include "error.h"
#include "object_manager.h"


struct rotary_encoder{
    uint8_t status;
    uint8_t transitions[4];
    uint8_t mask;
    int8_t state_counter;
};

typedef struct rotary_encoder * RotaryEncoder;

RotaryEncoder rotary_encoder_create(uint8_t pin_a, uint8_t pin_b);

void rotary_encoder_update(RotaryEncoder rotary_encoder, uint8_t data);

void rotary_encoder_update_with_queue(RotaryEncoder rotary_encoder, Queue queue, uint8_t remove_used_elements);

int8_t rotary_encoder_get_counter(RotaryEncoder rotary_encoder);

void rotary_encoder_reset_counter(RotaryEncoder rotary_encoder);

#endif	/* ROTARY_ENCODER_H */

