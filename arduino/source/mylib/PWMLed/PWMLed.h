#pragma once
#include <Arduino.h>
#include <Led.h>

class PWMLed : public Led {
protected:
    int value;  // 0 ~ 255

public:
    PWMLed(int pin);
    int getValue();
    void fadeIn(int step=1);    //점점 밝아짐
    void fadeOut(int step=1);   //점점 어두워짐
    void set(int value);
};