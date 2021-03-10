int i;
void setup() {
  for (i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(7, INPUT);
}
void loop() {
  if (digitalRead(7) == HIGH) {
    for (i = 6; i > 1; i--) {
      digitalWrite(i, HIGH);
      delay(1000);
      digitalWrite(i, LOW);
    }
  }
  else if(digitalRead(7) == LOW) {
    for (i = 2; i < 6; i++) {
      digitalWrite(i, HIGH);
      delay(1000);
      digitalWrite(i, LOW);
    }
  }
}
