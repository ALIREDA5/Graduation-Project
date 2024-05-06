/*
 * Stepper_M.c
 *
 * Created: 10/26/2023 1:17:29 AM
 *  Author: Ali Reda
 */ 
	
	/*----------------- Libraries and Definitions ------------*/
#include "../Lib/STD_Types.h"
#include "../MCAL/timer0/TIM0.h"
#include "../MCAL/DIO/DIO.h"
#include "Stepper.h"

	/*----------------- Functions Definitions ------------*/

void tog()
{
	DIO_vidTogglePin(step);
}

	/*------------------------- Function Definition of stepper motor to turn only one turn -----------------------------*/
void Stepper_ON(uint8 u8MotorDirection,uint8 u8SensorPin,uint8 u8MovementDirection)
{
	uint8 u8SensorValue;
	
	switch(u8MotorDirection)
	{
		case 0:
		DIO_enuSetPinValue(dir,1);
		break;
		case 1:
		DIO_enuSetPinValue(dir,0);
		break;
	}
	switch(u8MovementDirection)
	{
		case 0:
		DIO_enuSetPinValue(9,1);  // relay pin 1  --> Horizontal motor
		DIO_enuSetPinValue(10,0);
		case 1:
		DIO_enuSetPinValue(9,0);
		DIO_enuSetPinValue(10,1);	// relay pin 2 --> Vertical motor
	}
	DIO_enuSetPinValue(EN,0);
	while(1)
	{
		DIO_enuSetPinValue(step,1);
		_delay_us(150);
		DIO_enuSetPinValue(step,0);
		_delay_us(150);
		DIO_enuReadPinValue(u8SensorPin,&u8SensorValue);
		if (u8SensorValue==1)
		{
			DIO_enuSetPinValue(EN,1);
			break;
		}
		else if (u8SensorValue==5)
		{
			for (uint32 i=0; i<106666;i++)
			{
				DIO_enuSetPinValue(step,1);
				_delay_us(150);
				DIO_enuSetPinValue(step,0);
				_delay_us(150);
			}
			break;	
		}
	}
}

	/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
void Stepper_off()
{
	DIO_enuSetPinValue(EN,1);
}
