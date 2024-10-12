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
    unsigned char status;
    unsigned char transitions[4];
    unsigned char mask;
    signed char state_counter;
};

typedef struct rotary_encoder * RotaryEncoder;

RotaryEncoder rotary_encoder_create(unsigned char pin_a, unsigned char pin_b);

void rotary_encoder_update(RotaryEncoder rotary_encoder, unsigned char data);

void rotary_encoder_update_with_queue(RotaryEncoder rotary_encoder, Queue queue, unsigned char remove_used_elements);

signed char rotary_encoder_get_counter(RotaryEncoder rotary_encoder);

void rotary_encoder_reset_counter(RotaryEncoder rotary_encoder);

#endif	/* ROTARY_ENCODER_H */

