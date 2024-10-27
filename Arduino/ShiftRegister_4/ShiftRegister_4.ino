#define Time 0
int clockPin = 2;
int latchPin = 3;
int dataPin = 4;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  shiftOutByte(B10000000, ~B00000000);
  delay(Time);
  shiftOutByte(B01000000, ~B01100110);
  delay(Time);
  shiftOutByte(B00100000, ~B01100110);
  delay(Time);
  shiftOutByte(B00010000, ~B00000000);
  delay(Time);
  shiftOutByte(B00001000, ~B00000000);
  delay(Time);
  shiftOutByte(B00000100, ~B11111111);
  delay(Time);
  shiftOutByte(B00000010, ~B01000010);
  delay(Time);
  shiftOutByte(B00000001, ~B00111100);
  delay(Time);
}

void shiftOutByte(uint8_t Value1, uint8_t Value2) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, Value2);
  shiftOut(dataPin, clockPin, MSBFIRST, Value1);
  digitalWrite(latchPin, HIGH);
}
