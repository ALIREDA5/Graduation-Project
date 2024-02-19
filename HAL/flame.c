/*
 * IR_Sensor.c
 *
 * Created: 10/28/2023 11:36:31 PM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/
#include "STD_Types.h"
#include "DIO.h"	
#include "flame.h"
		/*--------------------- Global Variables ------------------*/

static uint8 FlamereadVlue;
		/*------------------------- Function Definitions -----------------------------*/
		
uint8 FlameSensor_ReadPinValue(void)
{
	DIO_enuReadPinValue(FLAMEPin , &FlamereadVlue);
	return FlamereadVlue;
}	
