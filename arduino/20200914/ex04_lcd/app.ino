#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(9600);
    lcd.init();

    lcd.setCursor(0, 0);
    lcd.print("Arduino LCD");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Welcome");
    delay(250);

    // LCD 백라이트 두번 점멸
    lcd.noBacklight();
    delay(250);
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
    lcd.backlight();
    delay(3000);
    // Open Serial Monitor Type to display 표시
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Open Serial Mntr");
    lcd.setCursor(0, 1);
    lcd.print("Type to display");
}

String readLine() {
    String line = "";
            while (Serial.available() > 0)
        {
            char ch = Serial.read();
            if (ch != '\r' && ch != '\n')
                line += ch;
        }
        return line;
}

void loop()
{

    if (Serial.available())
    {
        delay(100);
        // lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Message from PC");
        lcd.setCursor(0, 1);

        String line = readLine();
        if(line != ""){
            lcd.setCursor(0,1);
            char buf[17];   //문자열 끝에 null문자열 포함
            float d = 3.14159;
            char buf2[10];
            dtostrf(d, 5, 3, buf2);
            // sprintf(buf, "%-8s %04d", line.c_str(), 123);    // 양수면 우측정렬, 음수면 좌측정렬
            sprintf(buf, "%-8s %s   ", line.c_str(), buf2);
            lcd.print(buf); //const char* 타입
        }
    }
}