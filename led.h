/*** Original Blink and Buzz ***

#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();
void led_update();

#endif // included
*/





/*** Modified Variable Blink and Buzz(same functionality) ***

#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char redOn, greenOn;
extern unsigned char ledChanged;

void ledInit();
void ledUpdate();

#endif // included
*/





/*** Blink and Buzz Mod 1 ***/

#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char redOn, greenOn, ledChanged;

void ledInit();
void ledUpdate();

#endif

