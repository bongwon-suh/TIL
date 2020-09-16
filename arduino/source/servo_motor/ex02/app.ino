#include <Servo.h>
#include <AnalogSensor.h>

Servo servo;
int servoPin = 9;

AnalogSensor poten(A0, 0, 179);

void setup(){
    servo.attach(servoPin);
    servo.write(0);
    delay(15);
}

void loop(){
    int val = poten.read();
    servo.write(val);
    delay(15);
}