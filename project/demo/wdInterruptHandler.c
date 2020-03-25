#include <msp430.h>
#include "stateMachines.h"
#include "dimStateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT() {
  static char blink_count = 0;
  if(++blink_count == tempo) {
    if(current_switch == 1) {
      song_1();
    }
    else if(current_switch == 2) {
      song_2();
    }
    else if(current_switch == 3) {
      song_2();
    }
    blink_count = 0;
  }
  if(current_switch == 3) {
    sm_fast_clock();
    sm_update_led();
    led_update();
  }
  else if(current_switch == 4) {
    mspOff();
  }
}
