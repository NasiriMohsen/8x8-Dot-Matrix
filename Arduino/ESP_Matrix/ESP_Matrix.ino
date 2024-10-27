#include <BluetoothSerial.h>

#define clockPin 13
#define latchPin 12
#define dataPin 14

BluetoothSerial Bluetooth;

String StringData;
String DefaultFace = "Normal";

byte bitRow = 0b00000001;
bool Flip = true;

String Mode = DefaultFace;
int Color = 1;
int Time = 10;
int Timer = 250;
int Brightness = 1;

const byte Empty[8] =             {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
const byte Full[8] =              {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

const byte OpenMouthSmile[8] =    {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b11111111, 0b01000010, 0b00111100};
const byte ClosedMouthSmile[8] =  {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b11111111, 0b01111110, 0b00000000};

const byte OpenMouth[8] =         {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b01111110, 0b01000010, 0b00111100};
const byte ClosedMouth[8] =       {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b01111110, 0b01111110, 0b00000000};

const byte LaughDown[8] =         {0b00000000, 0b01000010, 0b10100101, 0b00000000, 0b00000000, 0b11111111, 0b01000010, 0b00111100};
const byte LaughUp[8] =           {0b01000010, 0b10100101, 0b00000000, 0b00000000, 0b11111111, 0b01000010, 0b00111100, 0b00000000};

const byte HeartEmpty[8] =        {0b01100110, 0b10011001, 0b10000001, 0b10000001, 0b10000001, 0b01000010, 0b00100100, 0b00011000};
const byte HeartHalfEmpty[8] =    {0b01100110, 0b11111111, 0b11011011, 0b11000011, 0b11000011, 0b01100110, 0b00111100, 0b00011000};
const byte HeartHalfFull[8] =     {0b01100110, 0b11111111, 0b11111111, 0b11100111, 0b11100111, 0b01111110, 0b00111100, 0b00011000};
const byte HeartFull[8] =         {0b01100110, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000};

const byte HeartUp[8] =           {0b01100110, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000, 0b00000000, 0b00000000};
const byte HeartMid[8] =          {0b00000000, 0b01100110, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000, 0b00000000};
const byte HeartDown[8] =         {0b00000000, 0b00000000, 0b01100110, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000};

const byte NormalBlink[8] =        {0b00000000, 0b00000000, 0b01100110, 0b00000000, 0b00000000, 0b01000010, 0b00111100, 0b00000000};
const byte Normal[8] =            {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b01000010, 0b00111100, 0b00000000};
  
const byte PokerBlink[8] =        {0b00000000, 0b00000000, 0b01100110, 0b00000000, 0b00000000, 0b01111110, 0b00000000, 0b00000000};
const byte Poker[8] =             {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b01111110, 0b00000000, 0b00000000};

const byte Kiss[8] =              {0b00000000, 0b01000010, 0b10100101, 0b00000000, 0b00000000, 0b00011000, 0b00011000, 0b00000000};



void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  Serial.begin(115200);
  
  Bluetooth.begin("Tracker");
}

void loop() {
  if (Mode == "Fill") {
    Matrix(Full, Color, 1, Brightness);
  } else if (Mode == "Kiss") {
    Matrix(Kiss, Color, 1, Brightness);
  } else if (Mode == "Normal") {
    Matrix(Normal, Color, 1, Brightness);
  } else if (Mode == "Laugh") {
    for (int i = 0; i < Time; i++) {
      Matrix(LaughDown, Color, Timer, Brightness);
      Matrix(LaughUp, Color, Timer, Brightness);
    }
    Matrix(LaughDown, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "Poker") {
    for (int i = 0; i < Time; i++) {
      Matrix(Poker, Color, Timer, Brightness);
      Matrix(PokerBlink, Color, Timer, Brightness);
    }
    Matrix(Poker, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "Smile") {
    for (int i = 0; i < Time; i++) {
      Matrix(Normal, Color, Timer, Brightness);
      Matrix(NormalBlink, Color, Timer, Brightness);
    }
    Matrix(Normal, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "Love") {
    for (int i = 0; i < Time; i++) {
      Matrix(HeartMid, Color, Timer, Brightness);
      Matrix(HeartUp, Color, Timer, Brightness);
      Matrix(HeartMid, Color, Timer, Brightness);
      Matrix(HeartDown, Color, Timer, Brightness); 
    }
    Matrix(HeartMid, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "FadeLove") {
    for (int i = 0; i < Time; i++) {
      Matrix(HeartEmpty, Color, Timer, Brightness);
      Matrix(HeartHalfEmpty, Color, Timer, Brightness);
      Matrix(HeartHalfFull, Color, Timer, Brightness); 
      Matrix(HeartFull, Color, Timer, Brightness);
      Matrix(HeartHalfFull, Color, Timer, Brightness); 
      Matrix(HeartHalfEmpty, Color, Timer, Brightness);
    }
    Matrix(HeartEmpty, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "Talk") {
    for (int i = 0; i < Time; i++) {
      Matrix(ClosedMouth, Color, Timer, Brightness);
      Matrix(OpenMouth, Color, Timer, Brightness);
    }
    Matrix(ClosedMouth, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "SmileTalk") {
    for (int i = 0; i < Time; i++) {
      Matrix(ClosedMouthSmile, Color, Timer, Brightness);
      Matrix(OpenMouthSmile, Color, Timer, Brightness);
      }
    Matrix(ClosedMouthSmile, Color, Timer, Brightness);
    Mode = DefaultFace;
  } else if (Mode == "Flip") {
      Flip = !Flip;
      Mode = DefaultFace;
    }
  else {
    Matrix(Empty, Color, 1, 1);
  }
  
  while (Bluetooth.available()) {
    char Data = Bluetooth.read();
    StringData += Data;
  }
  if (StringData.length() > 0) {
    Mode = StringData.substring(0, StringData.indexOf(','));
    Color = StringData.substring(StringData.indexOf(',') + 1, StringData.indexOf(',', StringData.indexOf(',') + 1)).toInt();
    Time = StringData.substring(StringData.indexOf(',', StringData.indexOf(',') + 1) + 1, StringData.indexOf(',', StringData.indexOf(',', StringData.indexOf(',') + 1) + 1)).toInt();
    Timer = StringData.substring(StringData.indexOf(',', StringData.indexOf(',', StringData.indexOf(',') + 1) + 1) + 1, StringData.lastIndexOf(',')).toInt();
    Brightness = StringData.substring(StringData.lastIndexOf(',') + 1).toInt();

    Bluetooth.println("Done");
    Serial.print("Mode: ");
    Serial.println(Mode);
    Serial.print("Color: ");
    Serial.println(Color);
    Serial.print("Time: ");
    Serial.println(Time);
    Serial.print("Timer: ");
    Serial.println(Timer);
    Serial.print("Brightness: ");
    Serial.println(Brightness);
    StringData = "";
  }
}

void Matrix(const byte Patern[8], int Color, int Time, int Brightness) {
  for (int k = 0; k < ceil(float(Time) / Brightness); k++) {
    if (Flip == false){
      bitRow = 0b10000000;
    } else{
      bitRow = 0b00000001;
    }
    for (int k = 0; k < Brightness; k++) {
      for (int i = 0; i < 8; i++) {
        if (Color == 1){
          shiftOutByte(bitRow, ~Patern[i],~0b00000000);
        } else if (Color == 2){
          shiftOutByte(bitRow, ~0b00000000,~Patern[i]);
        } else{
          shiftOutByte(bitRow, ~Patern[i],~Patern[i]);
        }
        if (Flip == false){
          bitRow >>= 1;
        } else{
          bitRow <<= 1;
        }
      }
    }
  }
}

void shiftOutByte(uint8_t Row, uint8_t GreenCol, uint8_t RedCol) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, RedCol);
  shiftOut(dataPin, clockPin, MSBFIRST, GreenCol);
  shiftOut(dataPin, clockPin, MSBFIRST, Row);
  digitalWrite(latchPin, HIGH);
}
