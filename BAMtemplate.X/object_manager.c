#include "object_manager.h"


uint8_t object_manager_memory[OBJECT_MANAGER_SIZE];
uint16_t object_manager_used_memory = 0;

void * object_manager_allocate(uint16_t size){
    ERROR_ASSERT(size + object_manager_used_memory <= OBJECT_MANAGER_SIZE, ERROR_CODE_OBJECT_MANAGER_NOT_ENOUGH_SPACE);
    void * ptr = (object_manager_memory + object_manager_used_memory);
    object_manager_used_memory += size;
    return ptr;
}

uint16_t object_manager_used_size(void){
    return object_manager_used_memory;
}

uint16_t object_manager_unused_size(void){
    return OBJECT_MANAGER_SIZE - object_manager_used_memory;
}

void object_manager_print_info(void){
    #if OBJECT_MANAGER_PRINT
    print_str("object_manager:\n   reserved byte: ");
    print_int64(OBJECT_MANAGER_SIZE);
    print_str("\n   used byte: ");
    print_int64(object_manager_used_size());
    print_nl();
    #else
    print_str("OBJECT_MANAGER_PRINT not enabled\n");
    #endif
}
