#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3,0);

    lcd.print("Hello, world!");
}

void loop() {
    lcd.backlight();
    delay(1000);
    lcd.noBacklight();
    delay(1000);
}