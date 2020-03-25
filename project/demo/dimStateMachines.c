#include <msp430.h>
#include "dimStateMachines.h"
#include "led.h"

//stating variables
static enum {off=0, dim=1, bright=2} ledMode;
static char pwmCount =0;

void
sm_fast_clock()
{
  pwmCount = (pwmCount + 1) & 3;
}

void
sm_update_led()
{
  char new_red_on;
  char new_green_on;
  new_red_on = (pwmCount < 1);
  new_green_on = (pwmCount < 1);
  if (red_on != new_red_on) {
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
}
