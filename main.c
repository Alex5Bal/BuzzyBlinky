/*** Original Blink and Buzz ***

#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"		 for setPeriod
#include "led.h"		 for led_control()

int
main()
{
    configureClocks();		 setup master oscillator, CPU & peripheral clocks
    buzzer_init();

    led_init();

    enableWDTInterrupts();	 enable wd timer

    or_sr(0x18);		 CPU off, GIE on
}*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"		 for setPeriod
#include "led.h"		 for led_control()

int
main() {

	configureClocks();		 setup master oscillator, CPU & peripheral clocks
    buzzerInit();
    ledInit();
    enableWDTInterrupts();	 enable wd timer
    or_sr(0x18);		 CPU off, GIE on
}*/




/*** Blink and Buzz Mod 1 ***/

#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main() {

	configureClocks();
    buzzerInit();
    ledInit();
    switchInit();
    enableWDTInterrupts();
    or_sr(0x18);
}


