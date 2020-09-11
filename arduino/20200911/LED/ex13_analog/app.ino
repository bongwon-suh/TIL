int pin_LED = 11;

void setup() {
    pinMode(pin_LED, OUTPUT);
}

void loop(){
    for(int i=0;i<255;i++){
        analogWrite(pin_LED, i);
        delay(20);
    }

    for(int i=255; i>=0; i--){
        analogWrite(pin_LED,i);
        delay(20);
    }
}