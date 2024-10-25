/* 
 * File:   object_manager.h
 * Author: Benni
 *
 * Created on October 12, 2024, 4:19 PM
 * 
 * This header allows for memory allocation.
 */

#ifndef OBJECT_MANAGER_H
#define	OBJECT_MANAGER_H

#include "config.h"
#include "print.h"
#include "error.h"

/*
 * Receives a pointer to a memory range with the specified size.
 * @param   size    The size (according to sizeof) that is reserved
 * @return  The pointer to the reserved memory range
 */
void * object_manager_allocate(uint16_t size);

/*
 * Returns the bytes that have been reserved.
 * @return  The number of bytes that have been reserved
 */
uint16_t object_manager_used_size(void);

/*
 * Returns the number of still available bytes.
 * @return  The number of still available bytes.
 */
uint16_t object_manager_unused_size(void);

/*
 * Prints information about the memory usage of the file over the serial
 * communication.
 */
void object_manager_print_info(void);

#endif	/* OBJECT_MANAGER_H */

