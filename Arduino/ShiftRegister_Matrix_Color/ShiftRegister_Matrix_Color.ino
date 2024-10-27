#define clockPin 13
#define latchPin 12
#define dataPin 14

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

const byte Heart[8] = {
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
 };
 
const byte HeartUp[8] = {
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000,
  B00000000
};
 
const byte HeartMid[8] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

const byte HeartDown[8] = {
  B00000000,
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};



void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int color = 1; color < 4; color++){
    for (int k = 0; k < 500; k++) {
      Matrix(HeartMid,color);
    }
    for (int i = 0; i < 5; i++) {
      for (int k = 0; k < 100; k++) {
        Matrix(HeartUp,color);
      }
      for (int k = 0; k < 100; k++) {
        Matrix(HeartMid,color);
      }
      for (int k = 0; k < 100; k++) {
        Matrix(HeartDown,color);
      }
      for (int k = 0; k < 100; k++) {
        Matrix(HeartMid,color);
      }
    }
  }
}









void Matrix(const byte Patern[8],int color) {
  byte bitRow = B10000000;
  for (int i = 0; i < 8; i++) {
    if (color == 1){
      shiftOutByte(bitRow, ~Patern[i],~B00000000);
    } else if (color == 2){
      shiftOutByte(bitRow, ~B00000000,~Patern[i]);
    } else{
      shiftOutByte(bitRow, ~Patern[i],~Patern[i]);
    }
    bitRow >>= 1;
  }
}
void shiftOutByte(uint8_t Row, uint8_t GreenCol, uint8_t RedCol) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, RedCol);
  shiftOut(dataPin, clockPin, MSBFIRST, GreenCol);
  shiftOut(dataPin, clockPin, MSBFIRST, Row);
  digitalWrite(latchPin, HIGH);
}
