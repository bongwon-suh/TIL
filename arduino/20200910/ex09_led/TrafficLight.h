#ifndef __TRAFFIC_LIGHT_H__
#define __TRAFFIC_LIGHT_H__

#include <Arduino.h>

class TrafficLight {
private:    // 멤버 변수 접근 제한자
    int redLED;
    int greenLED;
    int yelloLED ;

public:     // 멤버 함수 접근 제한자
    TrafficLight(int greenLED, int yelloLED, int redLED);

    void go(int duration=0);
    void stop(int duration=0);
    void leftTurn(int duration=0);
    void blink(int pin, int duration);
    void leftTurnBlink(int duration=0);
    
    void run(); // 신호등 운영 메소드


};

#endif