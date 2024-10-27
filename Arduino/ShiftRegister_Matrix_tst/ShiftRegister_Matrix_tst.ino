int clockPin = 2;
int latchPin = 3;
int dataPin = 4;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      turnOnSingleLED(row, col);
      delay(100);  // Adjust delay to control LED speed
    }
  }
}

void turnOnSingleLED(int row, int col) {
  // Create a bitmask to select the current row and column
  byte rowBit = B10000000 >> row;    // Row bit pattern
  byte colBit = ~(B10000000 >> col); // Column bit pattern (active LOW)
  
  shiftOutByte(rowBit, colBit, B11111111);
}

void shiftOutByte(uint8_t Row, uint8_t GreenCol, uint8_t RedCol) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, RedCol);
  shiftOut(dataPin, clockPin, MSBFIRST, GreenCol);
  shiftOut(dataPin, clockPin, MSBFIRST, Row);
  digitalWrite(latchPin, HIGH);
}
