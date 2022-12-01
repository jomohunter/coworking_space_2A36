
//#include <LiquidCrystal.h>  //include LCD library (standard library)
#include <Keypad.h>         //include keypad library - first you must install library (library link in the video description)
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

Servo servo;
//char* password ="12345"; //create a password
int pozisyon = 0;  //keypad position

const byte rows = 4;  //number of the keypad's rows and columns
const byte cols = 4;

char keyMap[rows][cols] = {  //define the cymbols on the buttons of the keypad

  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[rows] = { 11, 10, 9, 8 };  //pins of the keypad²²²
byte colPins[cols] = { 7, 6, 5, 4 };
int i = 0, k = 0;
char arr[10];
char data;
int buzz = 13;  //buzzer
Keypad keypad = Keypad(makeKeymap(keyMap), rowPins, colPins, rows, cols);
int Position = 0; // position of the servo
bool SmartDoor = true; // the servo 
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(buzz, OUTPUT);
  /*lcd.setCursor(3,0);
  lcd.setCursor(2,1);
 lcd.setCursor(0,1);*/
  Serial.begin(9600);
  servo.attach(12); // attaches the servo to pin 10
  ServoClose();
}

void loop() {

  char whichKey = keypad.getKey();  //define which key is pressed with getKey
  if (pozisyon == 0) {
    
    lcd.setCursor(0, 0);
    lcd.print("    Welcome");
    
       
    lcd.setCursor(0, 1);
    lcd.print(" Enter Password");
  }
  if (Serial.available()>0) {
    lcd.setCursor(0, 0);
    pozisyon = 0;
    i = 0;
    k = 0;
    data = Serial.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(data);
    data = Serial.read();
    lcd.clear();
    lcd.print(data);
    if (data == "F") {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("wrong");
      delay(1000);

      /*  lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Invalid code!");
        tone(buzz, 261);
        delay(1000);
        noTone(buzz);
        lcd.clear();*/
      pozisyon = 0;
      i = 0;
      k = 0;
    }
    else{
      ServoOpen();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("*** Verified ***");
      tone(buzz, 3000, 500);
      delay(1000);
      for (int j = 0; j < 5; j++) {
        arr[j] = "";
      }
      delay(3000);
      lcd.clear();
      pozisyon = 0;
      i = 0;
      k = 0;
    }
  }

  if (whichKey == '*' || whichKey == '#' || whichKey == 'A' ||  //define invalid keys
      whichKey == 'B' || whichKey == 'C' || whichKey == 'D') {

    pozisyon = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
    i = 0;
    k = 0;
  } else if (whichKey == '0' || whichKey == '1' || whichKey == '2' || whichKey == '3' || whichKey == '4' || whichKey == '5' || whichKey == '6' || whichKey == '7' || whichKey == '8' || whichKey == '9') {
    //  lcd.clear();
    tone(buzz, 1000);
    delay(200);
    noTone(buzz);
    lcd.setCursor(i, 0);
    lcd.clear();
    lcd.print(whichKey);
    delay(300);
    arr[k] = whichKey;
    k++;
    i++;
  }
  if (pozisyon != 6 && k == 5) {
    pozisyon = 0;
    i = 0;
    lcd.clear();
  }

  if (k == 5) {
    Serial.write(arr);
    k = 0;
    for (int j = 0; j < 5; j++) {
      arr[j] = "";
    
    }
  }
}

void ServoOpen() // opens the servo
{
  for (Position = 180; Position >= 0; Position -= 5) { // moves from 0 to 180 degrees
    servo.write(Position); // moves to the postion
    delay(15); // waits 15 milliseconds
  }
}

void ServoClose() // closes the servo
{
  for (Position = 0; Position <= 180; Position += 5) { // moves from position 0 to 180 degrees
    servo.write(Position); // moves to the position
    delay(15); // waits 15 milliseconds
  }
}