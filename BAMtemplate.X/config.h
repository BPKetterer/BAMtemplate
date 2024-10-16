/* 
 * File:   config.h
 * Author: Benni
 *
 * Created on September 29, 2024, 12:52 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

/*
 * Helper macros
 */
#define ENABLED 1
#define DISABLED 0
#define M_HZ 1000000UL

/*
 * Supported MCU types.
 */
typedef enum{
    MCU_TYPE_ATMEGA_168PA
} mcu_type;



/* -+-+-----------------------------------------+-+- */
/* -+-+- Hardware specific configurations:     -+-+- */
/* -+-+- These configurations need to be       -+-+- */
/* -+-+- adjusted by the user/programmer.      -+-+- */
/* -+-+- See documentation (tbd.) for details. -+-+- */
/* -+-+--VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV--+-+- */

/* TODO adjust these configurations according to your requirements*/
#define MCU_TYPE                MCU_TYPE_ATMEGA_168PA
#define F_CPU                   (1 * M_HZ)
#define ERROR_CHECK             ENABLED
#define OBJECT_MANAGER_SIZE     50
#define MIN_PAUSE_US            0
#define OBJECT_MANAGER_PRINT    DISABLED



/* -+-+--------------------------------+-+- */
/* -+-+- Verify configuration macros: -+-+- */
/* -+-+--VVVVVVVVVVVVVVVVVVVVVVVVVVVV--+-+- */

#ifndef MCU_TYPE
#error "MCU_TYPE not defined in config.h"
#endif
#ifndef F_CPU
#error "F_CPU not defined in config.h"
#endif
#ifndef ERROR_CHECK
#error "ERROR_CHECK not defined in config.h"
#endif
#ifndef OBJECT_MANAGER_SIZE
#error "OBJECT_MANAGER_SIZE not defined in config.h"
#endif
#ifndef MIN_PAUSE_US
#error "MIN_PAUSE_US not defined in config.h"
#endif
#ifndef OBJECT_MANAGER_PRINT
#error "OBJECT_MANAGER_PRINT not defined in config.h"
#endif

#endif	/* CONFIG_H */

