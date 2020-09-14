#include "Led.h"
#include "button.h"
Led led(4);
Button btn(11);

int count = 0;

void setup() {
    Serial.begin(9600);
}

void work() {
    led.toggle();
}

void loop() {
    led.set(btn.read());
}