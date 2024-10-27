#define Time 300
int clockPin = 2;
int latchPin = 3;
int dataPin = 4;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  shiftOutByte(B11111111, ~B00000000, ~B00001000);
  delay(Time);

}

void shiftOutByte(uint8_t Row, uint8_t GreenCol, uint8_t RedCol) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, Row);
  shiftOut(dataPin, clockPin, MSBFIRST, RedCol);
  shiftOut(dataPin, clockPin, MSBFIRST, GreenCol);
  digitalWrite(latchPin, HIGH);
}
