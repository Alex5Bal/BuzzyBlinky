/*** Original Blink and Buzz ***

#ifndef switches_included
#define switches_included

#define SW1 BIT3		 switch1 is p1.3
#define SWITCHES SW1		 only 1 switch on this board

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed;  effectively boolean

#endif // included
*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#ifndef switches_included
#define switches_included

#define SW1 BIT3		 switch1 is p1.3
#define SWITCHES SW1		 only 1 switch on this board

void switchInit();
void switchInterruptHandler();

extern char switchStateDown, switchStateChanged;

#endif // included
*/




/*** Blink and Buzz Mod 1 ***/

#ifndef switches_included
#define switches_included

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

void switchInit();
void switchInterruptHandler();

extern char switchStateDown, switchStateChanged;

#endif // included
