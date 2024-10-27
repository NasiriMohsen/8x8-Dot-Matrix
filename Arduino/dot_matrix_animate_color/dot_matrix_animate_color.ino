const int RowPins[8] = {36, 34, 32, 30, 22, 24, 26, 28};
const int RedColPins[8] = {37, 35, 33, 31, 23, 25, 27, 29};
const int GreenColPins[8] = {52, 50, 48, 46, 38, 40, 42, 44};

const byte OpenMouthSmile[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11111111,
  B01000010,
  B00111100
};

const byte ClosedMouthSmile[8] = {
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
  B01000010,
  B10100101,
  B00000000,
  B00000000,
  B01000010,
  B00100100,
  B00011000
};

const byte Surprised[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00011000
};

const byte OpenMouth[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B01111110,
  B01000010,
  B00111100
};
const byte ClosedMouth[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B01111110,
  B01111110,
  B00000000
};

const byte LaughDown[8] = {
  B00000000,
  B1000010,
  B10100101,
  B00000000,
  B00000000,
  B11111111,
  B1000010,
  B00111100
};

const byte LaughUp[8] = {
  B1000010,
  B10100101,
  B00000000,
  B00000000,
  B11111111,
  B1000010,
  B00111100,
  B00000000
};

const byte Empty[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

const byte Full[8] = {
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};

const byte Poker[8] = {
  B00000000,
  B00000000,
  B00100100,
  B00000000,
  B00000000,
  B01111110,
  B00000000,
  B00000000
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(RowPins[i], OUTPUT);
    pinMode(RedColPins[i], OUTPUT);
    pinMode(GreenColPins[i], OUTPUT);
    digitalWrite(RowPins[i], LOW);   
    digitalWrite(RedColPins[i], HIGH);
    digitalWrite(GreenColPins[i], HIGH);    
  }
}

void displayPattern(const byte pattern[8],int color) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(RowPins[i], HIGH);
    for (int j = 0; j < 8; j++) {
      if (bitRead(pattern[i], j)) {
        if (color == 1){
          digitalWrite(RedColPins[j], LOW);
          digitalWrite(GreenColPins[j], HIGH);
        } else if (color == 2){
          digitalWrite(RedColPins[j], HIGH);
          digitalWrite(GreenColPins[j], LOW);
        } else{
          digitalWrite(RedColPins[j], LOW);
          digitalWrite(GreenColPins[j], LOW);
        }
      } else {
        digitalWrite(RedColPins[j], HIGH);
        digitalWrite(GreenColPins[j], HIGH);
      }
    }
    delay(2);
    digitalWrite(RowPins[i], LOW);
  }
}


void loop() {
  for (int c = 0; c < 3; c++) {
    for (int i = 0; i < 5; i++) {
      for (int k = 0; k < 10; k++) {
        displayPattern(OpenMouthSmile,c);
      }
      for (int k = 0; k < 10; k++) {
        displayPattern(ClosedMouthSmile,c);
      }
    }
  
  //smile
    for (int k = 0; k < 100; k++) {
      displayPattern(Smile,c);
    }
  
    for (int i = 0; i < 5; i++) {
      for (int k = 0; k < 10; k++) {
        displayPattern(OpenMouth,c);
      }
      for (int k = 0; k < 10; k++) {
        displayPattern(ClosedMouth,c);
      }
    }
  
  //Surprised
    for (int k = 0; k < 100; k++) {
      displayPattern(Surprised,c);
    }
  
    for (int i = 0; i < 10; i++) {
      for (int k = 0; k < 10; k++) {
        displayPattern(LaughUp,c);
      }
      for (int k = 0; k < 10; k++) {
        displayPattern(LaughDown,c);
      }
    }
    //Poker
    for (int k = 0; k < 100; k++) {
      displayPattern(Poker,c);
    }
  }
}
