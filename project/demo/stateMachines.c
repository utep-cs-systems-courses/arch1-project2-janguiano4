#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void greenLed() {
  green_on = 1;
  red_on = 0;
  led_changed = 1;
  led_update();
}

void redLed() {
  green_on = 0;
  red_on = 1;
  led_changed = 1;
  led_update();
}

void ledOn() {
  green_on = 1;
  red_on = 1;
  led_changed = 1;
  led_update();
}

void ledOff() {
  green_on = 0;
  red_on = 0;
  led_changed = 1;
  led_update();
}

void sadness_and_sorrow() {
  static char change = 0;
  static char flag = 0;
  switch (change) {
  case 0:
    change = 1;
    buzzer_set_period(987);
    tempo = 30;
    greenLed();
    break;
  case 1:
     change = 2;
     buzzer_set_period(880);
     tempo = 250;
     redLed();
     break;
  case 2:
    change = 3;
    buzzer_set_period(659);
    tempo = 60;
    greenLed();
    break;
  case 3:
    change = 4;
    buzzer_set_period(880);
    tempo = 60;
    redLed();
    break;
  case 4:
    change = 5;
    buzzer_set_period(1046);
    tempo = 120;
    greenLed();
    break;
  case 5:
    change = 7;
    buzzer_set_period(1174);
    tempo = 250;
    redLed();
    break;
  case 6:
    change = 7;
    buzzer_set_period(880);
    tempo = 250;
    ledOn();
    break;
  case 7:
    change = 8;
    buzzer_set_period(1046);
    tempo = 60;
    ledOn();
    break;
  case 8:
    change = 9;
    buzzer_set_period(987);
    tempo = 60;
    redLed();
    break;
  case 9:
    change = 10;
    buzzer_set_period(1046);
    tempo = 60;
    greenLed();
    break;
  case 10:
    change = 11;
    buzzer_set_period(1174);
    tempo = 60;
    redLed();
    break;
  case 11:
    change = 12;
    buzzer_set_period(784);
    tempo = 250;
    greenLed();
    break;
  case 12:
    change = 13;
    buzzer_set_period(1318);
    tempo = 250;
    redLed();
    break;
  case 13:
    if(flag == 0) {
      change = 0;
      flag = 1;
    }
    else {
      change = 14;
    }
    buzzer_set_period(1174);
    tempo = 250;
    ledOn();
    break;
  case 14:
    change = 15;
    buzzer_set_period(880);
    tempo = 250;
    ledOn();
    break;
  case 15:
    change = 16;
    buzzer_set_period(880);
    tempo = 250;
    ledOn();
    break;
  case 16:
    change = 17;
    buzzer_set_period(0);
    tempo = 250;
    ledOff();
    break;
  case 17:
    change = 0;
    buzzer_set_period(0);
    tempo = 30;
    ledOff();
    flag = 0;
    break;
  }
}

void lavender_town(){
  static char note = 0;
  switch(note) {
  case 0:
    note = 1;
    buzzer_set_period(1046);
    tempo = 120;
    greenLed();
    break;
  case 1:
    note = 2;
    buzzer_set_period(1318);
    tempo = 120;
    redLed();
    break;
  case 2:
    note = 3;
    buzzer_set_period(1760);
    tempo = 120;
    ledOn();
    break;
  case 3:
    note = 0;
    buzzer_set_period(1396);
    tempo = 120;
    ledOff();
    break;
  }
}
void mspOff(){
  buzzer_set_period(0);
  ledOff();
}

    
