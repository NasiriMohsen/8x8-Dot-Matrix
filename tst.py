import serial
from TTS import TextToSpeech

Bluetooth = serial.Serial('COM10', 115200)
text_reader = TextToSpeech()

text_reader.set_property(voice_id=1, rate=125, volume=0.9)

while True:
    Sentence= input("Enter the data: ")
    print(len(Sentence.split(' ')))   
    Bluetooth.write(f"Talk,1,{len(Sentence.split(' '))},500,1".encode('utf-8'))
    text_reader.speak_text(Sentence)
    
    

#Normal,1,10,500,1
#Normal,1,10,500,1
#Normal,1,10,500,1
#
#Laugh,1,10,500,1  
#Laugh,2,10,500,1 
#Laugh,3,10,500,1 
#
#Poker,1,1,5000,1
#Poker,2,1,5000,1 
#Poker,3,1,5000,1 
#
#
#Love,1,10,500,1   
#Love,2,10,500,1 
#Love,3,10,500,1 
#
#FadeLove,3,10,500,1 
#FadeLove,2,10,500,1 
#FadeLove,1,10,500,1 
#
#Talk,1,10,500,1     
#Talk,2,10,500,1 
#Talk,3,10,500,1 
#
#SmileTalk,1,10,500,1 
#SmileTalk,2,10,500,1 
#SmileTalk,3,10,500,1 
