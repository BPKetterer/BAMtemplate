#include "queue.h"


Queue queue_create(uint8_t length){
    ERROR_ASSERT(length, ERROR_CODE_QUEUE_INVALID_SIZE);
    volatile uint8_t * data = object_manager_allocate(sizeof(volatile uint8_t) * length);
    Queue queue = object_manager_allocate(sizeof(struct queue));
    queue->data = data;
    queue->first = 0;
    queue->max_length = length;
    queue->used_length = 0;
    return queue;
}

void queue_append(Queue queue, uint8_t data){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length < queue->max_length, ERROR_CODE_QUEUE_FULL);
    queue->data[(queue->first + queue->used_length) % queue->max_length] = data;
    queue->used_length++;
}

uint8_t queue_pop(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length, ERROR_CODE_QUEUE_EMPTY);
    uint8_t data = queue->data[queue->first];
    queue->first = (queue->first + 1) % queue->max_length;
    queue->used_length--;
    return data;
}

uint8_t queue_get(Queue queue, uint8_t id){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used_length < id, ERROR_CODE_QUEUE_INVALID_IDX);
    return queue->data[(queue->first + id) % queue->max_length];
}

uint8_t queue_size(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    return queue->used_length;
}

void queue_clear(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    queue->used_length = 0;
}
