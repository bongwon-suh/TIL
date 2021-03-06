#pragma once
#include <Arduino.h>

class AnalogSensor{
protected:
    int pin;
    int toMin;  //map의 새로운 범위 최소값
    int toMax;  //map의 새로운 범위 최대값

public:
    AnalogSensor(int pin, int toMin=0, int toMax=255);
    void setRange(int toMin, int toMax);
    int read();
};