/*
 * IR_Sensor.c
 *
 * Created: 10/28/2023 11:36:31 PM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/
#include "../Lib/STD_Types.h"
#include "../MCAL/DIO/DIO.h"
#include "IR Sensor.h"
		/*--------------------- Global Variables ------------------*/

static uint16 u16IRValue;
		
// pin will be High as any thing within the Detection Distance
// The potentiometer R5 is used to adjust how sensitive the sensor is. 
// You can use it to adjust the distance from the object at which the sensor detects it.

		/*------------------------- Function Definitions -----------------------------*/
		
uint8 IR_Read(uint8 u8IRPin)
{
	 DIO_enuReadPinValue(u8IRPin,&u16IRValue); 
	return u16IRValue;
}