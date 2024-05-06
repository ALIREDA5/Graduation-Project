/*
 * Servo_module.c
 *
 * Created: 4/26/2024 5:45:31 PM
 *  Author: Ali Reda
 */ 


#include "../Lib/STD_Types.h"
#include "../HAL/LCD.h"
#include "../HAL/Servo.h"

void Servo_module(uint8 u8ServoState)
{
	// servo control
	if (u8ServoState == 1);
	{
		Servo_Angle(180);
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Enter your Car ");
	}
	if (u8ServoState == 0)
	{
		Servo_Angle(0);
	}
}