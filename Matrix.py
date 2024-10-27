import serial

Bluetooth = serial.Serial('COM10', 115200)


while True:
    Data = input("Enter the data: ")
    Bluetooth.write(Data.encode('utf-8'))

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
