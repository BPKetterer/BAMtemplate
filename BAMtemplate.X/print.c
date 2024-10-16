#include "print.h"


void print_hex_half(uint8_t h);


void print_str(char *str){
    while(*str != '\0'){
        serial_send(*str);
        str++;
    }
}

void print_char(char c){
    serial_send(c);
}

void print_int64(int64_t n){
    if(n < 0){
        serial_send('-');
        print_uint64((uint64_t) -n);
    } else {
        print_uint64((uint64_t) n);
    }
}

void print_uint64(uint64_t n){
    uint8_t d = (uint8_t)(n % 10);
    if(n >= 10){
        print_uint64(n / 10);
    }
    serial_send('0' + d);
}

void print_float(float f){
    print_int64((uint64_t) f);
    serial_send('.');
    float r = f - (float)(uint64_t)f;
    do{
        r *= 10;
        serial_send('0' + (uint8_t) r);
        r -= (uint8_t) r;
    }while(r > 0.000001f);
}

void print_hex_byte(uint8_t b){
    print_hex_half(b >> 4);
    print_hex_half(b & ((1 << 4) - 1));
}

void print_bin_byte(uint8_t b){
    uint8_t bit_mask = 1 << 7;
    while(bit_mask){
        if(b & bit_mask){
            serial_send('1');
        } else {
            serial_send('0');
        }
        bit_mask >>= 1;
    }
}

void print_bool(uint8_t b){
    if(b){
        print_str("true");
    } else {
        print_str("false");
    }
}

void print_nl(void){
    serial_send('\n');
}

void print_hex_half(uint8_t h){
    if(h <= 9){
        serial_send('0' + h);
    } else {
        serial_send('A' + h - 10);
    }
}