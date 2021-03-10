int i, v;
void setup() {
  for (i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(1, INPUT);
}
void loop() {

  for (i = 2; i < 6; i++) {
    if (digitalRead(7) == HIGH) {
      v = 500;
    }
    else if (digitalRead(8) == HIGH) {
      v = 1000;
    }
     else if (digitalRead(9) == HIGH) {
      v = 1000;
    }
     else if (digitalRead(1) == HIGH) {
      v = 1000;
    }
    else{
      v=0;
    }
    if(v!=0){
    digitalWrite(i, HIGH);
    delay(v);
    digitalWrite(i, LOW);
  }
  else{
    digitalWrite(i,LOW);
  }
  }


}
