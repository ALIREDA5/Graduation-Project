/*
 * Stepper_V.c
 *
 * Created: 1/26/2024 11:51:55 PM
 *  Author: Ali Reda
 */ 
#include "../MCAL/TIMER2/TIM2.h"
#include "Stepper_V.h"

void StepperV_ON(directionV d)
{
	
	// Full_Step:
	DIO_enuSetPinValue(DMODE0,0);
	DIO_enuSetPinValue(DMODE1,0);
	DIO_enuSetPinValue(DMODE2,0);
	
	switch(d)
	{
		case up:
		DIO_enuSetPinValue(DIR,1);
		break;
		case down:
		DIO_enuSetPinValue(DIR,0);
		break;
	}
	DIO_enuSetPinValue(ENAPLE,1);
	
	TIM2_vidInit();
	// connect step pin to OCR2 
}

void StepperV_off()
{
	DIO_enuSetPinValue(ENAPLE,0);
}