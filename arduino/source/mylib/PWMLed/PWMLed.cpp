#include "PWMLed.h"

PWMLed::PWMLed(int pin) : Led(pin), value(0) {

}

int PWMLed::getValue(){
    return value;
}

void PWMLed::fadeIn(int step){
    value += step;
    if(value>255){
        value=0;
    }
    analogWrite(pin, value);
}

void PWMLed::fadeOut(int step){
    value -= step;
    if(value<0){
        value=255;
    }
    analogWrite(pin, value);
}

//set override
void PWMLed::set(int value){
    analogWrite(pin, value);
}