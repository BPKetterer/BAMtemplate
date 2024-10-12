/* 
 * File:   object_manager.h
 * Author: Benni
 *
 * Created on October 12, 2024, 4:19 PM
 */

#ifndef OBJECT_MANAGER_H
#define	OBJECT_MANAGER_H

#include "config.h"
#include "print.h"

#ifndef OBJECT_MANAGER_SIZE
#error "OBJECT_MANAGER_SIZE not defined in config.h"
#endif

void * object_manager_allocate(unsigned int size);

unsigned int object_manager_used_size(void);

unsigned int object_manager_unused_size(void);

void object_manager_print_info(void);

#endif	/* OBJECT_MANAGER_H */

