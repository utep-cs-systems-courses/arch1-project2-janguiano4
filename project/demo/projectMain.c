#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"

int main() {
  configureClocks();

  buzzer_init();
  switch_init(); //watchdog and state machine will be called on button press
  led_init();

  or_sr(0x18);  //CPU off, GIE on
}
