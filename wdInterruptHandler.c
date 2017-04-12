/*#include <msp430.h>
#include "buzzer.h"
#include "led.h"

void decisecond()
{
  static char cnt = 0;		 # deciseconds/frequecy change
  if (++cnt > 2) {
    buzzer_advance_frequency();
    cnt = 0;
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT(){	 250 interrupts/sec
  static char second_count = 0, decisecond_count = 0;
  if (++second_count == 250) {
    state_advance();//led_toggle();
    second_count = 0;
  }
  if (++decisecond_count == 25) {
    buzzer_advance_frequency();
    decisecond_count = 0;
  }
  led_update();
}*/

#include <msp430.h>
#include "buzzer.h"
#include "led.h"

void decisecond() {

	static char count = 0;		/* # deciseconds/frequecy change */

	if (++count > 2) {

		buzzerAdvanceFrequency();
		count = 0;
  }
}

void __interrupt_vec(WDT_VECTOR) WDT() {

	static char secondCounter = 0, decisecondCounter = 0;

	if (++secondCounter == 250) {
    stateAdvance();
    secondCounter = 0;
	}

	if (++decisecondCounter == 25) {
    buzzerAdvanceFrequency();
    decisecondCounter = 0;
	}

	ledUpdate();
}
