const byte Y[8] = { B10000001, B01000010, B00100100, B00011000, B00011000, B00011000, B00011000, B00000000 };
const byte O[8] = { B00111100, B01000010, B10000001, B10000001, B10000001, B01000010, B00111100, B00000000 };
const byte U[8] = { B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B01111110, B00000000 };
const byte F[8] = { B11111111, B10000000, B10000000, B11111110, B10000000, B10000000, B10000000, B00000000 };
const byte K[8] = { B10000001, B10000110, B10011000, B11100000, B10011000, B10000110, B10000001, B00000000 };
const byte C[8] = { B00111110, B01000001, B10000000, B10000000, B10000000, B01000001, B00111110, B00000000 };

const byte* helloWorld[] = { F, U, C, K, ,Y, O, U};

int clockPin = 2;
int latchPin = 3;
int dataPin = 4;

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
  scrollText(helloWorld, 5, 1,50);  
}







void scrollText(const byte* letters[], int numLetters, int color, int Time) {
  for (int pos = 0; pos < numLetters * 8; pos++) {
    for (int i = 0; i < Time; i++) {
      for (int row = 0; row < 8; row++) {
        byte displayRow = B00000000;
        for (int i = 0; i < numLetters; i++) {
          int letterCol = pos - i * 8;
          if (letterCol >= 0 && letterCol < 8) {
            displayRow |= ((letters[i][row] << letterCol) & B11111111);
          }
        }
        if (color == 1){
          shiftOutByte(B10000000 >> row, ~displayRow,~B00000000);
        } else if (color == 2){
          shiftOutByte(B10000000 >> row, ~B00000000,~displayRow);
        } else{
          shiftOutByte(B10000000 >> row, ~displayRow,~displayRow);
        }
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
