int clockPin = 2;
int latchPin = 3;
int dataPin = 4;

const byte Empty[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}
;

const byte Face[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11111111,
  B01000010,
  B00111100
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  Matrix(Face);
}

void Matrix(const byte Patern[8]) {
  byte bitRow = B10000000;
  for (int i = 0; i < 8; i++) {
    shiftOutByte(bitRow, ~Patern[i]);
    bitRow >>= 1;
  }
}

void shiftOutByte(uint8_t Row, uint8_t Col) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, Row);
  shiftOut(dataPin, clockPin, MSBFIRST, Col);
  digitalWrite(latchPin, HIGH);
}
