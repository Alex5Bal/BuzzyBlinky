/*** Original Blink and Buzz ***

#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
}*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#include <msp430.h>
#include "led.h"

unsigned char redOn = 0, greenOn = 0;
unsigned char ledChanged = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void ledInit() {

	P1DIR |= LEDS;		// bits attached to leds are output
	ledChanged = 1;
	ledUpdate();
}

void ledUpdate() {

	if (ledChanged) {
		char ledFlags = redVal[redOn] | greenVal[greenOn];

		P1OUT &= (0xff ^ LEDS) | ledFlags; // clear bit for off leds
		P1OUT |= ledFlags;		     // set bit for on leds
		ledChanged = 0;
	}
}*/





/*** Blink and Buzz Mod 1 ***/

#include <msp430.h>
#include "led.h"

unsigned char redOn = 0, greenOn = 0;
unsigned char ledChanged = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void ledInit() {

	P1DIR |= LEDS;		// bits attached to leds are output
	ledChanged = 1;
	ledUpdate();
}

void ledUpdate() {

	if (ledChanged) {
		char ledFlags = redVal[redOn] | greenVal[greenOn];

		P1OUT &= (0xff ^ LEDS) | ledFlags; // clear bit for off leds
		P1OUT |= ledFlags;		     // set bit for on leds
		ledChanged = 0;
	}
}
