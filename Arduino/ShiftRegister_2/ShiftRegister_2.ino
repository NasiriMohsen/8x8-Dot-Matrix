int dataPin = 2; //DS
int clockPin = 3; //SH_CP
int latchPin = 4; //ST_CP

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0B01010101);
  digitalWrite(latchPin, HIGH);
}
