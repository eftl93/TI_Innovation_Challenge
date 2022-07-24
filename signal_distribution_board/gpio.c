/*
 * File:   gpio.c
 * Author: eder0
 *
 * Created on July 23, 2022, 9:02 PM
 */
#include <xc.h>
#include <stdio.h>
#include "gpio.h"
#include "main.h"

void gpio_init(void)
{
   CM1CON0bits.C1ON=0; //disable comparator1 module
   CM2CON0bits.C2ON=0; //disable comparator2 module
   RED_LED_DIR = 0;     //set output for debugging led
   GREEN_LED_DIR = 0;   //set output for debugging led
   YELLOW_LED_DIR = 0;  //set output for debugging led
   TRISD    |= 0x03;  //output to control the relay for the beam lights
   debug_leds_off();
   

}

void high_beams_on(void)
{
    
}

void high_beams_off(void)
{
    LATD = 0b00000001; //reset the relay to turn on off the lights
    __delay_ms(10);
    __delay_ms(5);
    LATD=0;
}

void debug_leds_on(void)
{
    LATA |= 0x07;    
}

void debug_leds_off(void)
{
   LATA &= 0xF8;   //Turn off the onboard diagnostic LEDs  
}
