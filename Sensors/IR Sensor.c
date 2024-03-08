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
		
// pin will be High as any thing within the Detection Distance
// The potentiometer R5 is used to adjust how sensitive the sensor is. 
// You can use it to adjust the distance from the object at which the sensor detects it.

		/*------------------------- Function Definitions -----------------------------*/
		
uint8 IR1_ReadPinValue(void)
{
    uint8 IRreadVlue;
	DIO_enuReadPinValue(IR1Pin , &IRreadVlue);
	return IRreadVlue;
}
uint8 IR2_ReadPinValue(void)
{
    uint8 IRreadVlue;
	DIO_enuReadPinValue(IR2Pin , &IRreadVlue);
	return IRreadVlue;
}
uint8 IR3_ReadPin1Value(void)
{
    uint8 IRreadVlue;
	DIO_enuReadPinValue(IR3Pin , &IRreadVlue);
	return IRreadVlue;
}
uint8 IR4_ReadPin1Value(void)
{
    uint8 IRreadVlue;
	DIO_enuReadPinValue(IR4Pin , &IRreadVlue);
	return IRreadVlue;
}	
