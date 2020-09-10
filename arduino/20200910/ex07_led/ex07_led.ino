const int pin_LED1 = 13;
const int pin_LED2 = 12;
 

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
}

void loop() {
  digitalWrite(pin_LED1, HIGH);
  delay(500);
  
  digitalWrite(pin_LED1, LOW);
  digitalWrite(pin_LED2, HIGH);
  delay(500);

  digitalWrite(pin_LED1, HIGH);
  delay(500);

  digitalWrite(pin_LED1, LOW);
  digitalWrite(pin_LED2, LOW);
  delay(500);

  
}
