const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
    randomSeed(analogRead(A0));
}

void loop() {
    analogWrite(redPin, random(256));
    analogWrite(greenPin, random(256));
    analogWrite(bluePin, random(256));
    delay(1000);
}