#include "Ultra.h"

Ultra::Ultra(int echo, int trig) : echo(echo), trig(trig){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

int Ultra::read(){
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    int distance = pulseIn(echo, HIGH) / 58;

    return distance;
}