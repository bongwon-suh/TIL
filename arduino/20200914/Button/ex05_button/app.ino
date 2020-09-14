const int pin_button = 11;
long startTime = 0;
long swCounterTimer = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pin_button, INPUT_PULLUP);
}

void loop() {
    if(digitalRead(pin_button)==LOW){
        startTime = millis();
        while (digitalRead(pin_button)==LOW);
        
        swCounterTimer = millis() - startTime;

        Serial.print(swCounterTimer);
        Serial.println(" ms");
    }
}