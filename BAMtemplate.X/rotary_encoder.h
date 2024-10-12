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


typedef struct{
    unsigned char status;
    unsigned char transitions[4];
    unsigned char mask;
    signed char state_counter;
} RotaryEncoderStruct;

typedef RotaryEncoderStruct* RotaryEncoderHandle;

void rotary_encoder_init(RotaryEncoderHandle rotary_encoder, unsigned char pin_a, unsigned char pin_b);

void rotary_encoder_update(RotaryEncoderHandle rotary_encoder, unsigned char data);

void rotary_encoder_update_with_queue(RotaryEncoderHandle rotary_encoder, Queue queue, unsigned char remove_used_elements);

signed char rotary_encoder_get_counter(RotaryEncoderHandle rotary_encoder);

void rotary_encoder_reset_counter(RotaryEncoderHandle rotary_encoder);

#define ROTARY_ENCODER_HANDLE(rotary_encoder_struct) (&(rotary_encoder_struct))

#endif	/* ROTARY_ENCODER_H */

