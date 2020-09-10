int pin_LED=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_LED, HIGH);
  delay(500);
  digitalWrite(pin_LED, LOW);
  delay(500);

  digitalWrite(pin_LED, HIGH);
  delay(1000);
  digitalWrite(pin_LED, LOW);
  delay(1000);

  digitalWrite(pin_LED, HIGH);
  delay(2000);
  digitalWrite(pin_LED, LOW);
  delay(2000);
}
