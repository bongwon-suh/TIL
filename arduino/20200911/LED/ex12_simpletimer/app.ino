#include <SimpleTimer.h>
int pin_LED1 = 13;
int pin_LED2 = 12;
int pin_LED3 = 11;

SimpleTimer timer;

void blink_1000(){
    int state = digitalRead(pin_LED1);  // 지정한 핀의 현재 상태 읽기
    digitalWrite(pin_LED1, !state);
}

void blink_500(){
    int state = digitalRead(pin_LED2);
    digitalWrite(pin_LED2, !state);
}


void blink_200(){
    int state = digitalRead(pin_LED3);
    digitalWrite(pin_LED3, !state);
}

void setup() {
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
    timer.setInterval(1000, blink_1000);
    timer.setInterval(500, blink_500);
    timer.setInterval(200, blink_200);
}

void loop(){
    timer.run();
}