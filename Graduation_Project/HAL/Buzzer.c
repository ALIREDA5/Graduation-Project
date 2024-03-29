/*
 * Buzzer.c
 *
 * Created: 10/26/2023 1:54:39 AM
 *  Author: Ali Reda
 */ 
		/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/DIO/DIO.h"
#include "Buzzer.h"

		/*------------------------- Function Definitions -----------------------------*/

void Buzzer_on()
{
	DIO_enuSetPinValue(buzzer,1);
}

void Buzzer_off()
{
	DIO_enuSetPinValue(buzzer,0);
}

void Buzzer_toggle()
{
	
	DIO_vidTogglePin(buzzer);

}