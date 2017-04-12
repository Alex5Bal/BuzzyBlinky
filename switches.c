/*** Original Blink and Buzz ***

#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;  effectively boolean

static char
switch_update_interrupt_sense()
{
  char p1val = P1IN;
   update switch interrupt to detect changes from current buttons
  P1IES |= (p1val & SWITCHES);	 if switch up, sense down
  P1IES &= (p1val | ~SWITCHES);	 if switch down, sense up
  return p1val;
}

void
switch_init()			 setup switch
{
  P1REN |= SWITCHES;		 enables resistors for switches
  P1IE = SWITCHES;		 enable interrupts from switches
  P1OUT |= SWITCHES;		 pull-ups for switches
  P1DIR &= ~SWITCHES;		 set switches' bits for input
  switch_update_interrupt_sense();
  switch_interrupt_handler();	 to initially read the switches
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1;  0 when SW1 is up
  switch_state_changed = 1;
  led_update();
}*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#include <msp430.h>
#include "switches.h"
#include "led.h"

char switchStateDown, switchStateChanged;

static char switchUpdateInterruptSense() {

	char p1val = P1IN;
	 update switch interrupt to detect changes from current buttons
	P1IES |= (p1val & SWITCHES);	 if switch up, sense down
	P1IES &= (p1val | ~SWITCHES);	 if switch down, sense up
	return p1val;
}

void switchInit() {

	P1REN |= SWITCHES;		 enables resistors for switches
	P1IE = SWITCHES;		 enable interrupts from switches
	P1OUT |= SWITCHES;		 pull-ups for switches
	P1DIR &= ~SWITCHES;		 set switches' bits for input
	switchUpdateInterruptSense();
	switchInterruptHandler();	 to initially read the switches
}

void switchInterruptHandler() {

	char p1val = switchUpdateInterruptSense();
	switchStateDown = (p1val & SW1) ? 0 : 1;  0 when SW1 is up
	switchStateChanged = 1;
	ledUpdate();
}*/





/*** Blink and Buzz Mod 1 ***/

#include <msp430.h>
#include "switches.h"
#include "led.h"

char switchStateDown, switchStateChanged;

static char switchUpdateInterruptSense() {

	char p1val = P1IN;

	P1IES |= (p1val & SWITCHES);
	P1IES &= (p1val | ~SWITCHES);
	return p1val;
}

void switchInit() {

	P1REN |= SWITCHES;
	P1IE = SWITCHES;
	P1OUT |= SWITCHES;
	P1DIR &= ~SWITCHES;
	switchUpdateInterruptSense();
	switchInterruptHandler();
}

void switchInterruptHandler() {

	char p1val = switchUpdateInterruptSense();
	switchStateDown = (p1val & SW1) ? 0 : 1;
	switchStateChanged = 1;
	ledUpdate();
}
