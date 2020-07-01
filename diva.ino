#include <Keyboard.h>
byte ButtonPins[] = {A0,A1,A2,A3,A4};
byte SinglePins[] = {A5,A6,A7,A8};

void setup() {
  for(int i=0;i<5;i++){
    pinMode(ButtonPins[i], INPUT_PULLUP);
  }
  Serial.begin(9600) ;
  Keyboard.begin();
}

void loop() {
  if(digitalRead(ButtonPins[0]) == 0){
    Keyboard.press(0x27);
  }else{
    Keyboard.release(0x27);
  }
  if(digitalRead(ButtonPins[1]) == 0){
    Keyboard.press(0x28);
  }else{
    Keyboard.release(0x28);
  }
  if(digitalRead(ButtonPins[2]) == 0){
    Keyboard.press(0x25);
  }else{
    Keyboard.release(0x25);
  }
  if(digitalRead(ButtonPins[3]) == 0){
    Keyboard.press(0x26);
  }else{
    Keyboard.release(0x26);
  }
  if(digitalRead(ButtonPins[4]) == 1){
    Keyboard.press(0x29);
  }else{
    Keyboard.release(0x29);
  }
  for(int i=0;i<4;i++) {
    digitalWrite(SinglePins[i], digitalRead(ButtonPins[i]));
  }
}
