#pragma once
#include <Arduino.h>

typedef void(*button_callback_t)();

class Button {
protected:
    int pin;
    bool state_previous;
    bool state_current;
    void (*callback)();

    // button_callback_t callback;

public:
    Button(int pin);
    int read();
    int check();
    void setCallback(button_callback_t callback);
    };