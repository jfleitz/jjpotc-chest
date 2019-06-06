//#define DEBUG

/*
Title: A chest opener for JJPOTC
Description: This sketch simply just moves a servo from one position to another based on a switch w/a little debouncing.

Author: Jeremy Fleitz
5/31/2019 - Initial Revision


Hookup:
PD2 - Switch In
PD10 - Servo Out
PD13 - LED out (on the arduino nano)
*/
#include <Servo.h>

Servo svo;


//constants that may need to be adjusted:
const int openPos = 0; //degree position on the servo for the chest to be open
const int closedPos = 80; //degree position on the servo for the chest to be closed
const int openSpeedDelay = 15; //delay in ms for adjusting how fast the servo opens the chest
const int closeSpeedDelay = 15; //delay in ms for adjusting how fast the servo closes the chest
 
//delays
unsigned long debounceDelay = 50; //debouncing time in ms..shouldn't need to change

//pins
const int ledPin = 13;
const int servoPin = 10;
const int switchPin = 2;

//globals
int lastSwState = LOW;
int swState  = LOW;

unsigned long lastDebounceTime = 0;


void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(servoPin,OUTPUT);
  pinMode(switchPin,INPUT_PULLUP);
  
  svo.attach(servoPin); 

  MoveChest(false);
  
  #ifdef DEBUG
  Serial.println("chest-opener initialized");
  #endif
}

//MoveChest basically is the servo example from the Arduino library, except switching directions based on the value passed in
void MoveChest(bool open) {
  int pos;

  // set the LED:
  digitalWrite(ledPin, open);

  if (open) {  
    for (pos = closedPos; pos > openPos; pos--) {
      // in steps of 1 degree
      svo.write(pos);            
      delay(openSpeedDelay);                
    }  
  }
  else {
    for (pos = openPos; pos < closedPos; pos++) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      svo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(closeSpeedDelay);                       // waits 15ms for the servo to reach the position
    }  
  }    
}


//loop is based off of the debounce example from the Arduino library, with calling the MoveChest method when the switch really changed.
void loop() {
  int sample = digitalRead(switchPin);

  // If the switch changed, due to noise or pressing:
  if (sample != lastSwState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (sample != swState) {
      swState = sample;
      
      //Changed, so either Open or Close the chest.
      MoveChest(swState); 
    }
  }
  
  lastSwState = sample;
}
