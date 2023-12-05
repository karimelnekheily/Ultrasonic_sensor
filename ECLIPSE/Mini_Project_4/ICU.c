/*
 * ICU.c
 *
 *  Created on: Oct 11, 2023
 *      Author: karim
 */

#include "ICU.h"
#include"COMMON_MACROS.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include "GPIO.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile void (*g_callBackPtr)(void)=NULL_PTR;


ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*Function to initialize the ICU DRIVER
1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers*/
void ICU_init(const ICU_ConfigType *Config_Ptr ){
	GPIO_writePin(PORTD_ID,6,PIN_INPUT);
	TCNT1=0;
	ICR1=0;
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	TCCR1B=(TCCR1B&0xBF)|((Config_Ptr->edge)<<6);
	TCCR1B=(TCCR1B&0xF8)|((Config_Ptr->clock));
	TIMSK|=(1<<TICIE1);
}

void ICU_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr=a_ptr;
}
/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgetype){
	TCCR1B=(TCCR1B&0xBF)|(edgetype<<6);
}
/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void){
	TCNT1=0;
}
/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}

void ICU_deInit(void){
	/* Clear All Timer1/ICU Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);

	/* Reset the global pointer value */
	g_callBackPtr = NULL_PTR;
}
