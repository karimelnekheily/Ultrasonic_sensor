/*
 * Mini_project4_karim.c
 *
 *  Created on: Oct 13, 2023
 *      Author: karim
 */


#include "LCD.h"
#include"Ultrasonic.h"
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


int main(void){

	LCD_init();
	Ultrasonic_init();
	SREG|=(1<<7);

   uint16 display_distance=0;
   LCD_displayString("Distance=     cm");
   	while(1){
   		display_distance = Ultrasonic_readDistance();
   		LCD_moveCursor(0, 10);
   		LCD_intgerToString(display_distance);
   		if(display_distance<100)
   			LCD_displayCharacter(' ');
   		/*
   		 * delay between every trigger to make ultrasonic able to produce echo for every trigger
   		 * if i don't make delay ,not all triggers produce echo
   		 * (so i save power consumption) and benefit from every trigger
   	     */
   		_delay_ms(100);
   	}
}
