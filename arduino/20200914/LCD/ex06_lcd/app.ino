#include <SimpleTimer.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SimpleTimer timer;

void printTime(){
    char buf[17];
    unsigned long t = millis();
    
    t = t /1000;
    int h = t / 3600;
    int m = (t - (h*3600)) / 60;
    int s = t - (h*3600 + m * 60);

    sprintf(buf, "%02d:%02d:%02d", h,m,s);

    lcd.setCursor(0,0);
    lcd.print(buf);
}

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    timer.setInterval(1000, printTime);
}

void loop() {
    timer.run();
}