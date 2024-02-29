/*
 * IR_Sensor.c
 *
 * Created: 10/28/2023 11:36:31 PM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/
#include "STD_Types.h"
#include "DIO.h"	
#include "IR.h"
		/*--------------------- Global Variables ------------------*/

static uint8 IRreadVlue;
		
// pin will be High as any thing within the Detection Distance
// The potentiometer R5 is used to adjust how sensitive the sensor is. 
// You can use it to adjust the distance from the object at which the sensor detects it.

		/*------------------------- Function Definitions -----------------------------*/
		
uint8 IR_ReadPinValue(void)
{
	DIO_enuReadPinValue(IRPin , &IRreadVlue);
	return !IRreadVlue;
}	
