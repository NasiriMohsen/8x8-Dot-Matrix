int rowPins[8] = {36, 34, 32, 30, 22, 24, 26, 28};
int colPins1[8] = {37, 35, 33, 31, 23, 25, 27, 29};
int colPins[8] = {52, 50, 48, 46, 38, 40, 42, 44};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
    digitalWrite(rowPins[i], LOW);   
    digitalWrite(colPins[i], HIGH);    
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(rowPins[i], HIGH);   
      digitalWrite(colPins[j], LOW);    
      delay(100); 
      digitalWrite(rowPins[i], LOW);
      digitalWrite(colPins[j], HIGH); 
    }
  }
}
