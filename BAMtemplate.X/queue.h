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
    volatile unsigned char * data;
    unsigned char max_length;
    volatile unsigned char used_length;
    volatile unsigned char first;
};

typedef struct queue * Queue;

Queue queue_create(unsigned char length);

void queue_append(Queue queue, unsigned char data);

unsigned char queue_pop(Queue queue);

unsigned char queue_get(Queue queue, unsigned char id);

unsigned char queue_size(Queue queue);

void queue_clear(Queue queue);

#endif	/* QUEUE_H */

