int rowPins[8] = {36, 34, 32, 30, 22, 24, 26, 28};
int colPins[8] = {37, 35, 33, 31, 23, 25, 27, 29};

const byte OpenMouth[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11111111,
  B01000010,
  B00111100
};

const byte ClosedMouth[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11111111,
  B01111110,
  B00000000
};

const byte Smile[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B10000001,
  B01111110,
  B00000000
};

const byte Surprised[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B00111100,
  B01000010,
  B00111100
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
    digitalWrite(rowPins[i], LOW);   
    digitalWrite(colPins[i], HIGH);    
  }
}

void displayPattern(const byte pattern[8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rowPins[i], HIGH);
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j)) {
        digitalWrite(colPins[j], LOW);
      } else {
        digitalWrite(colPins[j], HIGH);
      }
    }
    delay(2);
    digitalWrite(rowPins[i], LOW);
  }
}

void loop() {

  for (int k = 0; k < 250; k++) {
    displayPattern(OpenMouth);
  }

  for (int k = 0; k < 250; k++) {
    displayPattern(ClosedMouth);
  }

  for (int k = 0; k < 250; k++) {
    displayPattern(Smile);
  }

  for (int k = 0; k < 250; k++) {
    displayPattern(Surprised);
  }
}
