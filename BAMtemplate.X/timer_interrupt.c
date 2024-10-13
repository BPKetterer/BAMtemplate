#include "timer_interrupt.h"

unsigned char calc_prescale(unsigned long us, unsigned long max_us_without_prescale);

void (*timer_interrupt_functions[TIMER_COUNT])(void *) = {};
void * timer_interrupt_data[TIMER_COUNT] = {};

void timer_interrupt_set_function(timer timer, void (*function)(void *), void * interrupt_data){
    timer_interrupt_functions[timer] = function;
    timer_interrupt_data[timer] = interrupt_data;
}

#define TIMER_INTERRUPT_CALL_FUNCTION(timer) (*timer_interrupt_functions[timer])(timer_interrupt_data[timer])

#if MCU_TYPE == ATMEGA_168PA

const unsigned int prescale_factors[] = {1, 8, 64, 256, 1024};
volatile unsigned char *prescale_byte[TIMER_COUNT] = {&TCCR0B, &TCCR1B, &TCCR2B};
volatile unsigned char *wave_form_byte[TIMER_COUNT] = {&TCCR0A, &TCCR1B , &TCCR2A};
unsigned char wave_form_bit[TIMER_COUNT] = {WGM01, WGM12 , WGM21};
volatile unsigned char *timer_enablement_byte[TIMER_COUNT] = {&TIMSK0, &TIMSK1, &TIMSK2};

ISR(TIMER0_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_0);
}

ISR(TIMER1_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_1);
}

ISR(TIMER2_COMPA_vect) {
    TIMER_INTERRUPT_CALL_FUNCTION(TIMER_2);
}

void timer_interrupt_set_period(timer timer, unsigned long us){
    unsigned long max_us_without_prescale;
    if(timer == TIMER_1){
        max_us_without_prescale = (float)(1UL << 16) / (F_CPU / 1000000);
    } else {
        max_us_without_prescale = (float)(1UL << 8) / (F_CPU / 1000000);
    }
    unsigned char prescale_id = calc_prescale(us, max_us_without_prescale);
    *prescale_byte[timer] = (*prescale_byte[timer] & ~(unsigned char)0b0111) | (prescale_id + 1);
    switch(timer){
        /*separate since TIMER_1 is 16 bytes*/
        case TIMER_0:
            OCR0A = (unsigned char)(us / prescale_factors[prescale_id] * (F_CPU / 1000000)) - 1;
            break;
        case TIMER_1:
            OCR1A = (uint16_t)(us / prescale_factors[prescale_id] * (F_CPU / 1000000)) - 1;
            break;
        case TIMER_2:
            OCR2A = (unsigned char)(us / prescale_factors[prescale_id] * (F_CPU / 1000000)) - 1;
            break;
        default:
            break;
    }
}

void timer_interrupt_enable(timer timer){
    /*TODO check timer valid*/
    *wave_form_byte[timer] |= (1 << wave_form_bit[timer]);
    *timer_enablement_byte[timer] |= 0b10;
}

void timer_interrupt_disable(timer timer){
    *timer_enablement_byte[timer] &= ~(unsigned char)0b10;
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

unsigned char calc_prescale(unsigned long us, unsigned long max_us_without_prescale){
    unsigned char prescale_id = 0;
    while(us / prescale_factors[prescale_id] > max_us_without_prescale && prescale_id + 1
            < sizeof(prescale_factors) / sizeof(prescale_factors[0])){
        prescale_id++;
    }
    /*TODO check if overflow*/
    return prescale_id;
}