int pin_LED1 = 13;
boolean LED_state1 = false;

int pin_LED2 = 12;
boolean LED_state2 = false;

void setup()
{
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);

    digitalWrite(pin_LED1, LED_state1);
    digitalWrite(pin_LED2, LED_state2);
}

void loop()
{
    // time_current = millis();
    // count ++;

    // if(time_current - time_previous >= 1000){
    //     time_previous = time_current;

    //     LED_state = !LED_state;
    //     digitalWrite(pin_LED, LED_state);

    //     Serial.println(count);
    //     count=0;
    // }

blink_led1();
blink_led2();

}

void blink_led1()
{
    static unsigned long time_previous = 0;
    const int INTERVAL = 500;
    unsigned long time_current = millis();
    if (time_current - time_previous > INTERVAL)
    {
        time_previous = time_current;
        LED_state1 = !LED_state1;
        digitalWrite(pin_LED1, LED_state1);
    }
}
void blink_led2()
{
    static unsigned long time_previous = 0;
    const int INTERVAL = 1000;
    unsigned long time_current = millis();
    if (time_current - time_previous > INTERVAL)
    {
        time_previous = time_current;
        LED_state2 = !LED_state2;
        digitalWrite(pin_LED2, LED_state2);
    }
}