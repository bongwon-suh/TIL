int pin_button = 11;
int led = 4;
boolean state_previous = true;
boolean state_current;
int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pin_button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}

void loop() {
    state_current = digitalRead(pin_button);
    if(!state_current){
        if(state_previous == true){
            state_previous = false;
            int ledState = digitalRead(led);
            digitalWrite(led, !ledState);
        }
        delay(10);
    }
    else{
        state_previous = true;
    }
}