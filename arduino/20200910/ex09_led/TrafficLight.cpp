#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenLED, int yelloLED, int redLED)
    : greenLED(greenLED), yelloLED(yelloLED), redLED(redLED) {
	pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(yelloLED, OUTPUT);
}

void TrafficLight:: go(int duration){
    digitalWrite(redLED, LOW);
    digitalWrite(yelloLED, LOW);
    digitalWrite(greenLED, HIGH);

    if(duration !=0){
        delay(duration);
    }
}
void TrafficLight:: stop(int duration){
    digitalWrite(redLED, HIGH);
    digitalWrite(yelloLED, LOW);
    digitalWrite(greenLED, LOW);
    if(duration !=0){
        delay(duration);
    }
}
void TrafficLight:: leftTurn(int duration){
    digitalWrite(redLED, LOW);
    digitalWrite(yelloLED, HIGH);
    digitalWrite(greenLED, HIGH);
    if(duration !=0){
        delay(duration);
    }
}
void TrafficLight::blink(int pin, int duration){
    digitalWrite(pin, HIGH);
    delay(duration/2);
    digitalWrite(pin, LOW);
    delay(duration/2);
}
void TrafficLight::leftTurnBlink(int duration){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    int interval = duration/5;
    for(int i=0;i<5;i++){
        blink(yelloLED, interval);
    }
}
    
void TrafficLight::run() // 신호등 운영 메소드
{
    go(5000);
    leftTurn(2000);
    leftTurnBlink(2000);
    stop(2000);

}