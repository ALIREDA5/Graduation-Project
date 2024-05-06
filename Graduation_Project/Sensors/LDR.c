/*
 * LDR.c
 *
 * Created: 10/29/2023 1:02:15 AM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/

#include "LDR.h"
		
		/*--------------------- Global Variables ------------------*/

static uint16 u16LDRValue;

		/*--------------------------- Function to return the percentage of max light intensity ----------------------------------*/

uint16 LDR_Read(uint8 u8LDRPin)
{
	 DIO_enuReadPinValue(u8LDRPin,&u16LDRValue);
	 return u16LDRValue;
}