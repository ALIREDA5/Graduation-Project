/*
 * To_Start.c
 *
 * Created: 1/26/2024 4:28:22 PM
 *  Author: Ali Reda
 */ 
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer1/TIM1.h"
#include "../MCAL/timer0/TIM0.h"
#include "../HAL/Servo.h"
#include "../HAL/Buzzer.h"
#include "../HAL/Stepper_V.h"
#include "../HAL/LCD.h"
#include "../Sensors/Ultrasonic_Sensor.h"
#include "APP.h"

uint8 flag=0;
uint8 flag1=0;

void Start(uint8 *state, uint8 *WC)
{
	// servo control
	if (strcmp(state,"Verified") && flag==0);
	{
		Servo_Angle(90);
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Enter your Car ");
		flag=1;
	}
	// ultrasonic sensor
	uint8 x= US_read(ADC1);
	if (x>10 && x<20 && flag1==0);
	{
		TIM0_vidSetCallBackCmp1(Buzzer_toggle,1000);
	}
	if (x<10 && flag1==0)
	{
		TIM0_vidSetCallBackCmp1(Buzzer_toggle,500);
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Stop");
	}
	uint8 p;
	if (DIO_enuReadPinValue(start,p) == 1)
	{
		flag1=1;
		Buzzer_off();
		StepperV_ON(up);
	}
	// Wireless Charging
	if (strcmp(WC,"WC,on"))
	{
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Wireless Charging is activated");
		DIO_enuSetPinValue(2,1);
	}
}