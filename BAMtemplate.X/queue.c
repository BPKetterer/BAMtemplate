#include "queue.h"


Queue queue_create(uint8_t length){
    ERROR_ASSERT(length, ERROR_CODE_QUEUE_INVALID_SIZE);
    volatile uint8_t * data = object_manager_allocate(sizeof(volatile uint8_t) * length);
    Queue queue = object_manager_allocate(sizeof(struct queue));
    queue->data = data;
    queue->length = length;
    queue->first_id = 0;
    queue->free_id = 0;
    queue->used = 0;
    return queue;
}

void queue_append(Queue queue, uint8_t data){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used < queue->length, ERROR_CODE_QUEUE_FULL);
    queue->data[queue->free_id] = data;
    queue->free_id = (queue->free_id + 1) % queue->length;
    queue->used++;
}

uint8_t queue_try_append(Queue queue, uint8_t data){
    if(queue->used >= queue->length){
        return 0;
    } else {
        queue_append(queue, data);
        return 1;
    }
}

uint8_t queue_pop(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used, ERROR_CODE_QUEUE_EMPTY);
    uint8_t data = queue->data[queue->first_id];
    queue->first_id = (queue->first_id + 1) % queue->length;
    queue->used--;
    return data;
}

uint8_t queue_get(Queue queue, uint8_t id){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    ERROR_ASSERT(queue->used < id, ERROR_CODE_QUEUE_INVALID_IDX);
    return queue->data[(queue->first_id + id) % queue->length];
}

uint8_t queue_size(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    return queue->used;
}

void queue_clear(Queue queue){
    ERROR_ASSERT(queue, ERROR_CODE_QUEUE_HANDLE_NULL);
    queue->used = 0;
    queue->first_id = queue->free_id;
}
