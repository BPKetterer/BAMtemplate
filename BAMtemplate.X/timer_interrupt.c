#include "timer_interrupt.h"

uint8_t calc_prescale(timer timer, uint32_t us, uint32_t max_us_without_prescale);

void (*timer_interrupt_functions[TIMER_COUNT])(void *) = {};
void * timer_interrupt_data[TIMER_COUNT] = {};

uint16_t *prescale_factors[TIMER_COUNT];
uint8_t prescale_factor_count[TIMER_COUNT];

#define TIMER_INTERRUPT_CALL_FUNCTION(timer) (*timer_interrupt_functions[timer])(timer_interrupt_data[timer])

#define TIMER_INTERRUPT_IS_LEGAL(timer) ((timer) >= 0 && (timer) < TIMER_COUNT)

void timer_interrupt_set_function(timer timer, void (*function)(void *), void * interrupt_data){
    ERROR_ASSERT(TIMER_INTERRUPT_IS_LEGAL(timer), ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER);
    timer_interrupt_functions[timer] = function;
    timer_interrupt_data[timer] = interrupt_data;
}

uint8_t calc_prescale(timer timer, uint32_t us, uint32_t max_us_without_prescale){
    uint8_t prescale_id = 0;
    while(us / prescale_factors[timer][prescale_id] > max_us_without_prescale
            && prescale_id + 1 < prescale_factor_count[timer]){
        prescale_id++;
    }
    return prescale_id;
}

#if MCU_TYPE == MCU_TYPE_ATMEGA_168PA

uint16_t prescale_factors_t01[] = {1, 8, 64, 256, 1024};
uint16_t prescale_factors_t2[] = {1, 8, 32, 64, 128, 256, 1024};

volatile uint8_t *timer_enablement_byte[TIMER_COUNT] = {&TIMSK0, &TIMSK1, &TIMSK2};

#define CALC_PERIOD(us, prescale) (us * (F_CPU / 1000000) / prescale - 1)

ISR(TIMER0_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_0);
}

ISR(TIMER1_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_1);
}

ISR(TIMER2_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_2);
}

void timer_interrupt_init(void){
    TCCR0A |= (1 << WGM01);
    TCCR1B |= (1 << WGM12);
    TCCR2A |= (1 << WGM21);
    prescale_factors[0] = prescale_factors[1] = prescale_factors_t01;
    prescale_factors[2] = prescale_factors_t2;
    prescale_factor_count[0] = prescale_factor_count[1] = 5;
    prescale_factor_count[2] = 7;
}

void timer_interrupt_set_period(timer timer, uint32_t us){
    ERROR_ASSERT(TIMER_INTERRUPT_IS_LEGAL(timer), ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER);
    ERROR_ASSERT(timer_interrupt_max_period_us(timer) >= us, ERROR_CODE_TIMER_INTERRUPT_OVERFLOW);
    uint32_t max_us_without_prescale;
    if(timer == TIMER_1){
        max_us_without_prescale = ((uint32_t)1 << 16) / (F_CPU / 1000000);
    } else {
        max_us_without_prescale = ((uint32_t)1 << 8) / (F_CPU / 1000000);
    }
    uint8_t prescale_id = calc_prescale(timer, us, max_us_without_prescale);
    switch(timer){
        /*separate since TIMER_1 is 16 bytes*/
        case TIMER_0:
            OCR0A = (uint8_t)CALC_PERIOD(us, prescale_factors[timer][prescale_id]);
            TCCR0B = (TCCR0B & ~(uint8_t)0b111) | (prescale_id + 1);
            break;
        case TIMER_1:
            OCR1A = (uint16_t)CALC_PERIOD(us, prescale_factors[timer][prescale_id]);
            TCCR1B = (TCCR1B & ~(uint8_t)0b111) | (prescale_id + 1);
            break;
        case TIMER_2:
            OCR2A = (uint8_t)CALC_PERIOD(us, prescale_factors[timer][prescale_id]);
            TCCR2B = (TCCR2B & ~(uint8_t)0b111) | (prescale_id + 1);
            break;
        default:
            break;
    }
}

void timer_interrupt_enable(timer timer){
    ERROR_ASSERT(TIMER_INTERRUPT_IS_LEGAL(timer), ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER);
    ERROR_ASSERT(timer_interrupt_functions[timer], ERROR_CODE_TIMER_INTERRUPT_FUNCTION_NULL);
    *timer_enablement_byte[timer] |= 0b10;
}

void timer_interrupt_disable(timer timer){
    ERROR_ASSERT(TIMER_INTERRUPT_IS_LEGAL(timer), ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER);
    *timer_enablement_byte[timer] &= ~(uint8_t)0b10;
}

void timer_interrupt_reset(timer timer){
    ERROR_ASSERT(TIMER_INTERRUPT_IS_LEGAL(timer), ERROR_CODE_TIMER_INTERRUPT_ILLEGAL_TIMER);
    switch(timer){
        /*separate since TIMER_1 is 16 bytes*/
        case TIMER_0:
            TCNT0 = 0;
            break;
        case TIMER_1:
            TCNT1H = 0;
            TCNT1L = 0;
            break;
        case TIMER_2:
            TCNT2 = 0;
            break;
        default:
            break;
    }
}

uint32_t timer_interrupt_max_period_us(timer timer){
    if(timer == TIMER_1){
        return ((uint32_t)1 << 16) / (F_CPU / 1000000) * 1024;
    } else {
        return ((uint32_t)1 << 8) / (F_CPU / 1000000) * 1024;
    }
}

#else
    #error "mcu type not implemented for timer_interrupt.c"
#endif