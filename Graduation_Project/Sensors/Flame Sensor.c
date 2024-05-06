/*
 * Flame_Sensor.c
 *
 * Created: 10/29/2023 1:02:51 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "../Lib/STD_Types.h"
#include "../MCAL//DIO/DIO.h"
#include "Flame Sensor.h"

/*--------------------- Global Variables ------------------*/

static uint16 u16FlameValue;

	
// PIN connected to the Flame Sensor should read 1 when fire is detected

/*------------------------- Function Definitions -----------------------------*/

uint16 Flame_Read(uint8 u8FlamePin)
{
	 DIO_enuReadPinValue(u8FlamePin,&u16FlameValue);
	return u16FlameValue;
}