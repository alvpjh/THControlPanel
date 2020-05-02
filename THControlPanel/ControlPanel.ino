#include "Keyboard.h"
#include "THDuinoBtn.h"
#define MAX_KEYS   18

THDuinoBtn g_BTNS[MAX_KEYS];

int BTNS_PINS[MAX_KEYS] = { 2 ,3  ,4  ,5  ,6  ,7  ,8  ,9  ,10 ,11 ,12 ,13 ,A0 ,A1 ,A2 ,A3 ,A4 ,A5  };
int CHARS_COD[MAX_KEYS] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','o','p','q','r','s'};



void setup() {
  for(int i =0; i<= 11;i++)
    pinMode(BTNS_PINS[i], INPUT_PULLUP);
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);
    pinMode(A5, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  for(int i =0; i< MAX_KEYS;i++)
    g_BTNS[i].vUpdate( !digitalRead( BTNS_PINS[i] ) );

  for(int i =0; i< MAX_KEYS;i++){
    if( g_BTNS[i].bPress() ) 
      Keyboard.press(CHARS_COD[i]);

     if( g_BTNS[i].bRelease() ) 
      Keyboard.release(CHARS_COD[i]);
  }

delay(10);
}

