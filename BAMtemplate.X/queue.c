#include "queue.h"


Queue queue_create(unsigned char length){
    ERROR_ASSERT(length, ERROR_CODE_QUEUE_INVALID_SIZE);
    volatile unsigned char * data = object_manager_allocate(sizeof(volatile unsigned char) * length);
    Queue queue = object_manager_allocate(sizeof(struct queue));
    queue->data = data;
    queue->first = 0;
    queue->max_length = length;
    queue->used_length = 0;
    return queue;
}

void queue_append(Queue queue, unsigned char data){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length < queue->max_length, ERROR_CODE_QUEUE_FULL);
    queue->data[(queue->first + queue->used_length) % queue->max_length] = data;
    queue->used_length++;
}

unsigned char queue_pop(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length, ERROR_CODE_QUEUE_EMPTY);
    unsigned char data = queue->data[queue->first];
    queue->first = (queue->first + 1) % queue->max_length;
    queue->used_length--;
    return data;
}

unsigned char queue_get(Queue queue, unsigned char id){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length < id, ERROR_CODE_QUEUE_INVALID_IDX);
    return queue->data[(queue->first + id) % queue->max_length];
}

unsigned char queue_size(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    return queue->used_length;
}

void queue_clear(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    queue->used_length = 0;
}
