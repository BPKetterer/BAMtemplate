/* 
 * File:   config.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:52 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#define ENABLED 1
#define DISABLED 0
#define M_HZ 1000000UL
#define ATMEGA_168PA 1


#define MCU_TYPE                ATMEGA_168PA
#define F_CPU                   (1 * M_HZ)
#define ERROR_CHECK             ENABLED
#define OBJECT_MANAGER_SIZE     200
#define MIN_PAUSE_US            0
#define OBJECT_MANAGER_PRINT    ENABLED
#define PRINT_CONFIG            ENABLED

#endif	/* CONFIG_H */

