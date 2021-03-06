#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

char switch_state_changed;
char switch_state_downS1, switch_state_downS2, switch_state_downS3, switch_state_downS4;
char current_switch;
int tempo;

static char
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  // update switch interrupt to detect changes from current buttons 
  P2IES |= (p1val & SWITCHES); // if switch up, sense down
  P2IES &= (p1val | ~SWITCHES); // if switch down, sense up
  return p1val;
}

void
switch_init() //setup switch
{
  P2REN |= SWITCHES; //enables resistors for switches
  P2IE = SWITCHES; // enable interrupts from switches
  P2OUT |= SWITCHES; //pull-ups for switches
  P2DIR &= ~SWITCHES; // set switches bits for input
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();

  switch_state_downS1 = (p1val & SW1) ? 0 : 1;
  switch_state_downS2 = (p1val & SW2) ? 0 : 1;
  switch_state_downS3 = (p1val & SW3) ? 0 : 1;
  switch_state_downS4 = (p1val & SW4) ? 0 : 1;

  if(switch_state_downS1) {
    current_switch = 1;
    tempo = 30;
  }
  else if(switch_state_downS2) {
    current_switch = 2;
    tempo = 120;
  }
  else if(switch_state_downS3) {
    current_switch = 3;
  }
  else if(switch_state_downS4) {
    current_switch = 4;
  }

  led_update();
  enableWDTInterrupts();
}

