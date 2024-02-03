/*
 * Stepper_M.c
 *
 * Created: 10/26/2023 1:17:29 AM
 *  Author: Ali Reda
 */ 
	
	/*----------------- Libraries and Definitions ------------*/
#include "../MCAL/timer0/TIM0.h"
#include "../MCAL/DIO/DIO.h"
#include "Stepper_H.h"

	/*----------------- Functions Definitions ------------*/

void tog()
{
	DIO_vidTogglePin(step);
}

	/*------------------------- Function Definition of stepper motor to turn only one turn -----------------------------*/
void StepperH_ON(direction d)
{
		// Full_Step:
		DIO_enuSetPinValue(MS1,0);
		DIO_enuSetPinValue(MS2,0);
		DIO_enuSetPinValue(MS3,0);
	
	switch(d)
	{
		case right:
		DIO_enuSetPinValue(dir,1);
		break;
		case left:
		DIO_enuSetPinValue(dir,0);
		break;
	}
	DIO_enuSetPinValue(enable,1);
	
	TIM0_vidInit();
	// // connect step pin to OCR0
	
}

	/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
void StepperH_off()
{
	DIO_enuSetPinValue(enable,0);
}
