#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 4, 0,
 false, false, false, false, false, false, false, false, false, false, false);

byte ButtonPins[] = {A0,A1,A2,A3};
byte ButtonCount = sizeof(ButtonPins) / sizeof(ButtonPins[0]);

void setup() {
  Serial.begin(9600) ;
  Joystick.begin(false);
}

void loop() {
  for(int i=0;i<ButtonCount;i++) {
    if(analogRead(ButtonPins[i]) > 0){
      Joystick.setButton (ButtonPins[i],1);
    }else{
      Joystick.setButton (ButtonPins[i],0);
    }
  }
  Joystick.sendState();
}
