#include "button.h"


Button button_create(port port, unsigned char pin){
    ERROR_ASSERT(port_is_valid(port), ERROR_CODE_BUTTON_ILLEGAL_PORT);
    ERROR_ASSERT(pin < 8, ERROR_CODE_BUTTON_ILLEGAL_PIN);
    PORT_SET_WRITE(port) &= ~((unsigned char)1 << pin);
    Button button = (Button) object_manager_allocate(sizeof(struct button));
    button->pin = pin;
    button->port_ptr_read = port_ptr_read(port);
    button->status = (*button->port_ptr_read >> pin & 1) - 1;
    return button;
}

void button_update(Button button){
    ERROR_ASSERT(button, ERROR_CODE_BUTTON_HANDLE_NULL);
    if(*button->port_ptr_read >> button->pin & 1){
        if(button->status < 0){
            button->status = 0;
        } else if(button->status < 127){
            button->status++;
        }
    } else {
        if(button->status >= 0){
            button->status = -1;
        } else if(button->status > -128){
            button->status--;
        }
    }
}

unsigned char button_is_pressed(Button button){
    ERROR_ASSERT(button, ERROR_CODE_BUTTON_HANDLE_NULL);
    return button->status >= 0;
}

unsigned char button_duration(Button button){
    ERROR_ASSERT(button, ERROR_CODE_BUTTON_HANDLE_NULL);
    if(button->status >= 0){
        return button->status;
    } else {
        return -1 - button->status;
    }
}
