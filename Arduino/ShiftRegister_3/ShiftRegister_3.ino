int clockPin = 2; // SH_CP
int latchPin = 3; // ST_CP
int dataPin = 4;  // DS

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  ShiftRegister(0B01010101);
  delay(500);
  
  ShiftRegister(0B10101010);
  delay(500);
}

void ShiftRegister(byte Values) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, Values);
  digitalWrite(latchPin, HIGH);
}
