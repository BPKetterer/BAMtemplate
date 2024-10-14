#include "timer_interrupt.h"

uint8_t calc_prescale(timer timer, uint32_t us, uint32_t max_us_without_prescale);

void (*timer_interrupt_functions[TIMER_COUNT])(void *) = {};
void * timer_interrupt_data[TIMER_COUNT] = {};

void timer_interrupt_set_function(timer timer, void (*function)(void *), void * interrupt_data){
    timer_interrupt_functions[timer] = function;
    timer_interrupt_data[timer] = interrupt_data;
}

#define TIMER_INTERRUPT_CALL_FUNCTION(timer) (*timer_interrupt_functions[timer])(timer_interrupt_data[timer])

#if MCU_TYPE == ATMEGA_168PA

const uint16_t prescale_factors_t01[] = {1, 8, 64, 256, 1024};
const uint16_t prescale_factors_t2[] = {1, 8, 32, 64, 128, 256, 1024};
const uint16_t *prescale_factors[TIMER_COUNT] = {prescale_factors_t01, prescale_factors_t01, prescale_factors_t2};
const uint8_t prescale_factor_count[TIMER_COUNT] = {5, 5, 7};
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
}

#include "log.h"
void timer_interrupt_set_period(timer timer, uint32_t us){
    uint32_t max_us_without_prescale;
    if(timer == TIMER_1){
        max_us_without_prescale = ((uint32_t)1 << 16) / (F_CPU / 1000000);
    } else {
        max_us_without_prescale = ((uint32_t)1 << 8) / (F_CPU / 1000000);
    }
    uint8_t prescale_id = calc_prescale(timer, us, max_us_without_prescale);
    /*todo check overflow*/
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
    /*TODO check timer valid*/
    *timer_enablement_byte[timer] |= 0b10;
}

void timer_interrupt_disable(timer timer){
    *timer_enablement_byte[timer] &= ~(uint8_t)0b10;
}

void timer_interrupt_reset(timer timer){
    /*TODO check timer valid*/
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

#else
    #error "mcu type not implemented for timer_interrupt.c"
#endif

uint8_t calc_prescale(timer timer, uint32_t us, uint32_t max_us_without_prescale){
    uint8_t prescale_id = 0;
    while(us / prescale_factors[timer][prescale_id] > max_us_without_prescale
            && prescale_id + 1 < prescale_factor_count[timer]){
        prescale_id++;
    }
    return prescale_id;
}