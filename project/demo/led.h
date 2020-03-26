#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void led_init(); // initialize leds
void led_update(); // updates leds

// these are boolean flags
extern unsigned char red_on, green_on;
extern unsigned char led_changed;
extern unsigned char leds_changed, green_led_state, red_led_state;

#endif

