/* 
 * File:   queue.h
 * Author: Benni
 *
 * Created on October 2, 2024, 7:08 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include "error.h"
#include "object_manager.h"

struct queue{
    volatile uint8_t * data;
    volatile uint8_t length;
    volatile uint8_t first_id;
    volatile uint8_t free_id;
    volatile uint8_t used;
};

typedef struct queue * Queue;

Queue queue_create(uint8_t length);

void queue_append(Queue queue, uint8_t data);

uint8_t queue_try_append(Queue queue, uint8_t data);

uint8_t queue_pop(Queue queue);

uint8_t queue_get(Queue queue, uint8_t id);

uint8_t queue_size(Queue queue);

void queue_clear(Queue queue);

#endif	/* QUEUE_H */

