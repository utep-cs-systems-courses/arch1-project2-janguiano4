#include <msp430.h>
#include "dimStateMachines.h"
#include "led.h"

//stating variables
static enum {off=0, dim=1, bright=2} ledMode;
static char pwmCount =0;

void
sm_fast_clock() //quickly cycle through 0...3
{
  pwmCount = (pwmCount + 1) & 3;
}

void
sm_update_led() //new function always keeps leds dim
{
  char new_red_on;
  char new_green_on;
  new_red_on = (pwmCount < 1); // 25% duty cycle
  new_green_on = (pwmCount < 1);
  if (red_on != new_red_on) {
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
}
