/*** Original Blink and Buzz ***

#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		 always toggle!
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			 always changes an led
}

char toggle_green()	 only toggle green if red is on!
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		 alternate between toggling red & green
{
  char changed = 0;

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggleRed() {		 //always toggle!

	static char state = 0;

	switch (state) {
	case 0:
		redOn = 1;
		state = 1;
		break;
	case 1:
		redOn = 0;
		state = 0;
		break;
	}
	return 1;			 //always changes an led
}

char toggleGreen()	{ //only toggle green if red is on!

	char changed = 0;
	if (redOn) {
		greenOn ^= 1;
		changed = 1;
	}
	return changed;
}


void stateAdvance() {		 //alternate between toggling red & green

	char changed = 0;

	static enum {R=0, G=1} color = G;

	switch (color) {
	case R: changed = toggleRed(); color = G; break;
	case G: changed = toggleGreen(); color = R; break;
	}

	ledChanged = changed;
	ledUpdate();
}*/





/*** Blink and Buzz Mod 1 ***/

#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggleRed() {

	static char state = 0;

	switch (state) {
		case 0:
			redOn = 1;
			state = 1;
			break;
		case 1:
			redOn = 0;
			state = 0;
			break;
	}

	return 1;
}

char toggleGreen()	{

	static char state = 0;

	switch (state) {
		case 0:
			greenOn = 0;
			state = 1;
			break;
		case 1:
			greenOn = 1;
			state = 0;
			break;
	}

	return 1;
}

void stateAdvance() {

	char changed = 0;

	static enum {R=0, G=1} color = G;

	switch (color) {
		case R:
			changed = toggleRed();
			color = G;
			break;

		case G:
			changed = toggleGreen();
			color = R;
			break;
	}

	ledChanged = changed;
	ledUpdate();
}

