/*
 * Limit_Switch.c
 *
 * Created: 10/29/2023 12:50:39 AM
 *  Author: Ali Reda
 */ 


		/*----------------- Libraries and Definitions ------------*/
#include "DIO.h"
#include "Limit Switch.h"

		/*--------------------- Global Variables ------------------*/

static uint8 u8LSValue;

		
// PIN connected to the limit switch should read 1 when switch is pressed in case of NO 
// remember to connect 10k resistor between the pin and limit switch

		/*------------------------- Function Definitions -----------------------------*/
uint8 LS_Read(uint8 u8pinCpy)
{
	 DIO_enuReadPinValue(u8pinCpy,&u8LSValue);
	return u8LSValue;
}
