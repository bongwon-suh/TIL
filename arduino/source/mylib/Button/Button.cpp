#include "button.h"

Button::Button(int pin) : pin(pin){
    pinMode(pin, INPUT_PULLUP);
    state_previous = true;
    callback = NULL;
}

void Button::setCallback(button_callback_t callback){
    this -> callback = callback;
}

int Button::read(){
    return !digitalRead(pin);
}

int Button::check() {
    state_current = digitalRead(pin);
    if(!state_current){
        if(state_previous == true){
            state_previous = false;
            if(callback != NULL){
                callback();
            }
        }
        delay(5);
    }
    else{
        state_previous = true;
    }
}