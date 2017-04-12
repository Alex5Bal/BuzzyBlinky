/*** Original Blink and Buzz ***

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static unsigned int period = 1000;
static signed int rate = 200;

#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

void buzzer_init()
{

       Direct timer A output "TA0.1" to P2.6.
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output

    timerAUpmode();		 used to drive speaker
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6;		 enable output to speaker (P2.6)

    buzzer_advance_frequency();	 start buzzing!!!
}

void buzzer_advance_frequency()
{
  period += rate;
  if ((rate > 0 && (period > MAX_PERIOD)) ||
      (rate < 0 && (period < MIN_PERIOD))) {
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;		 one half cycle
}*/




/*** Modified Variable Blink and Buzz(same functionality) ***

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static unsigned int period = 1000;
static signed int rate = 500;

#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

void buzzerInit() {

       Direct timer A output "TA0.1" to P2.6.
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output

    timerAUpmode();		 //used to drive speaker
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6;		 //enable output to speaker (P2.6)

    buzzerAdvanceFrequency();	 //start buzzing!!!
}

void buzzerAdvanceFrequency() {

	period += rate;

	if ((rate > 0 && (period > MAX_PERIOD)) ||
      (rate < 0 && (period < MIN_PERIOD))) {

		rate = -rate;
		period += (rate << 1);
	}

	buzzerSetPeriod(period);
}

void buzzerSetPeriod(short cycles) {

	CCR0 = cycles;
	CCR1 = cycles >> 5;
}*/




/*** Blink and Buzz Mod 1 ***/

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

unsigned int period = 0;
signed int rate = 1000;
unsigned char sounds = 0;

#define MIN_PERIOD 1000
#define MAX_PERIOD 6000

void buzzerInit() {

    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6;

    buzzerAdvanceFrequency();
}

void buzzerUpdate( ) {

	if (switchStateChanged & sounds == 1) {
		period += 100;
		rate += 100;
		sounds = 0;
	}

	else if (switchStateChanged && sounds == 0) {
		period += 500;
		rate += 200;
		sounds = 1;
	}

	switchStateChanged = 0;

}

void buzzerAdvanceFrequency() {

	period += rate;

	if ((rate > 0 && (period > MAX_PERIOD)) || (rate < 0 && (period < MIN_PERIOD))) {

		rate = -rate;
		period += (rate << 1);
	}

	buzzerSetPeriod(period);
}

void buzzerSetPeriod(short cycles) {

	CCR0 = cycles;
	CCR1 = cycles >> 1;
}



