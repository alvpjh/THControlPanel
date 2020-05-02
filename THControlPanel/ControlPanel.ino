/*
THControlPanel by Alvpjh
https://github.com/alvpjh/THControlPanel
02/05/2020

THControlPanel : 
-Firmware for Arduino Leonardo
-This project allows you to map the switches of your arcade board, to a specific key on your keyboard
*/

#include "Keyboard.h"
#include "THDuinoBtn.h"
#define MAX_KEYS   18

THDuinoBtn g_BTNS[MAX_KEYS];

//pin configuration
int BTNS_PINS[MAX_KEYS] = { 2 ,3  ,4  ,5  ,6  ,7  ,8  ,9  ,10 ,11 ,12 ,13 ,A0 ,A1 ,A2 ,A3 ,A4 ,A5  };
//key mapping
int CHARS_COD[MAX_KEYS] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','o','p','q','r','s'};


void setup() {
  for(int i =0; i< MAX_KEYS; i++)
    pinMode(BTNS_PINS[i], INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  
  // update THDuinoBtn object array
  for(int i =0; i< MAX_KEYS;i++)
    g_BTNS[i].vUpdate( !digitalRead( BTNS_PINS[i] ) );

  // for each entry, release keyboard event
  for(int i =0; i< MAX_KEYS;i++){
    if( g_BTNS[i].bPress() ) 
      Keyboard.press(CHARS_COD[i]);

     if( g_BTNS[i].bRelease() ) 
      Keyboard.release(CHARS_COD[i]);
  }
  
//the delay value can be set as your speed need, for this case 10 ms is enough
delay(10);
}

