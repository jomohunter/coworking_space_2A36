  

#include <Keypad.h>
#define PIN_W 12
#define PIN_LED 11
const byte ROWS = 4; 
const byte COLS = 4; 
char data;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
    

  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
    pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_W,OUTPUT);
//La LED reliée à la broche 12 est intialisé à l'état LOW
  digitalWrite(PIN_LED,LOW);
  digitalWrite(PIN_W,LOW);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.print(customKey);//affichage
  }

  if (Serial.available())
  {
    data=Serial.read();
    if (data=='1')
    {
      digitalWrite(PIN_LED,HIGH);
      digitalWrite(PIN_W,LOW);
    }
    if(data=='2')
    {
      digitalWrite(PIN_LED,LOW);
      digitalWrite(PIN_W,HIGH);
    }
  }
}
