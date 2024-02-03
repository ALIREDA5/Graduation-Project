/*
 * Servo.c
 *
 * Created: 10/9/2023 1:08:49 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/
#include "../Lib/STD_Types.h"
#include "../MCAL/Timer1/TIM1.h"
#include "../MCAL/DIO/DIO.h"
#include "Servo.h"
/*------------------------- Function Definitions -----------------------------*/

void Servo_Init(void)
{
	TIM1_vidInit() ;
	ICR1L = 19999;
	TIM1_SetOutputCmpAVal(999);
}

void Servo_Angle(uint8 angle)
{
	TIM1_SetOutputCmpAVal(((uint32)angle * 1000)/180 + 999);
}