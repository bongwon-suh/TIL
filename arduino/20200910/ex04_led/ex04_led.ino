int pin_LED = 13;

void blink(int pin, long time){
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin, LOW);
  delay(time);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink(pin_LED, 500);
  blink(pin_LED, 1000);
  blink(pin_LED, 2000);
}
