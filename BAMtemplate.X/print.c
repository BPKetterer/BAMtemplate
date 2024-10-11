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

void print_config(void){
    #if PRINT_CONFIG
    print_str("\n---\n");
    print_str("Selected MCU: ");
    #if ATMEGA_168PA
    print_str("ATMEGA_168PA\n");
    #else
    print_str("UNKNOWN!!!\n");
    #endif
    print_str("Expected clock frequency: ");
    print_float((float)(F_CPU) / 1000000);
    print_str(" MHz\n");
    #if ERROR_CHECK
    print_str("The system is checking for errors\n");
    #else
    print_str("The system is NOT checking for errors\n");
    #endif
    #if MIN_PAUSE_US
    print_str("pauses shorter than ");
    print_float(MIN_PAUSE_US);
    print_str(" us are skipped\n");
    #else
    print_str("No pauses are skipped");  
    #endif
    print_str("\n---\n");
    #else    
    print_str("\nPRINT_CONFIG not enabled\n");
    #endif
}