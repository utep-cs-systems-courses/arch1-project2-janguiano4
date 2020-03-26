#ifndef switches_included
#define switches_included

#define SW1 BIT0 // switch 1
#define SW2 BIT1 // sw 2
#define SW3 BIT2 // sw3
#define SW4 BIT3 // sw4
#define SWITCHES (SW1 | SW2 |SW3 | SW4)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_changed;
extern char current_switch; // to save which switch was pressed

//to know which switch was pressed down
extern char switch_state_downS1, switch_state_downS2, switch_state_downS3, switch_state_downS4;

extern int tempo;

#endif
