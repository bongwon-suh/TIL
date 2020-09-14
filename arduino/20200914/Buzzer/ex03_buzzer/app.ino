int speakerPin = 5;

void setup(){
    pinMode(speakerPin, OUTPUT);
}

void loop() {
    tone(speakerPin, 5000, 1000);
    delay(2000);
}