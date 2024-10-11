#include "print.h"


void print_hex_half(unsigned char h);


void print_str(char *str){
    while(*str != '\0'){
        serial_send(*str);
        str++;
    }
}

void print_char(char c){
    serial_send(c);
}

void print_long(long n){
    if(n < 0){
        serial_send('-');
        print_ulong((unsigned long) -n);
    } else {
        print_ulong((unsigned long) n);
    }
}

void print_ulong(unsigned long n){
    char d = (char)(n % 10);
    if(n >= 10){
        print_ulong(n / 10);
    }
    serial_send('0' + d);
}

void print_float(float f){
    print_long((unsigned long) f);
    serial_send('.');
    float r = f - (float)(unsigned long)f;
    do{
        r *= 10;
        serial_send('0' + (char) r);
        r -= (char) r;
    }while(r > 0.000001f);
}

void print_hex_byte(unsigned char b){
    print_hex_half(b >> 4);
    print_hex_half(b & ((1 << 4) - 1));
}

void print_bin_byte(unsigned char b){
    unsigned char bit_mask = 1 << 7;
    while(bit_mask){
        if(b & bit_mask){
            serial_send('1');
        } else {
            serial_send('0');
        }
        bit_mask >>= 1;
    }
}

void print_bool(unsigned char b){
    if(b){
        print_str("true");
    } else {
        print_str("false");
    }
}

void print_nl(void){
    serial_send('\n');
}

void print_hex_half(unsigned char h){
    if(h <= 9){
        serial_send('0' + h);
    } else {
        serial_send('A' + h - 10);
    }
}