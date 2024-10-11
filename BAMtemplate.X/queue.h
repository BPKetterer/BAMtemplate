/* 
 * File:   queue.h
 * Author: Benni
 *
 * Created on October 2, 2024, 7:08 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include "error.h"

typedef struct{
    volatile unsigned char * data;
    unsigned char max_length;
    volatile unsigned char used_length;
    volatile unsigned char first;
} QueueStruct;

typedef QueueStruct* QueueHandle;

void queue_init(QueueHandle queue, unsigned char *data_array, unsigned char length);

void queue_append(QueueHandle queue, unsigned char data);

unsigned char queue_pop(QueueHandle queue);

unsigned char queue_get(QueueHandle queue, unsigned char id);

unsigned char queue_size(QueueHandle queue);

void queue_clear(QueueHandle queue);

#define QUEUE_HANDLE(QueueStruct) (&(QueueStruct))

#endif	/* QUEUE_H */

