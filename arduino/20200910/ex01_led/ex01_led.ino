void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, false);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(1000);
}
