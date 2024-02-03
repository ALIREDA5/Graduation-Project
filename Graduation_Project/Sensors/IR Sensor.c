/*
 * IR_Sensor.c
 *
 * Created: 10/28/2023 11:36:31 PM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/
#include "../MCAL/DIO/DIO.h"
#include "IR Sensor.h"
		/*--------------------- Global Variables ------------------*/

static uint16 x;
		
// pin will be High as any thing within the Detection Distance
// The potentiometer R5 is used to adjust how sensitive the sensor is. 
// You can use it to adjust the distance from the object at which the sensor detects it.

		/*------------------------- Function Definitions -----------------------------*/
		
uint8_t IR_Read(uint8 p)
{
	 DIO_enuReadPinValue(p,x); 
	return x;
}

