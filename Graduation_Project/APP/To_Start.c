/*
 * To_Start.c
 *
 * Created: 1/26/2024 4:28:22 PM
 *  Author: Ali Reda
 */ 

#include "APP.h"

uint8 flag=0;
uint8 flag1=0;

void Start(uint8 *state)
{
	// servo control
	if (servo == 1 && flag==0);
	{
		Servo_Angle(180);
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Enter your Car ");
		flag=1;
	}
	// ultrasonic sensor
	uint16 x= ULTRASONIC_GetDistance();
	if (x>5 && x<10 && flag1==0);
	{
		Buzzer_toggle();
		DIO_enuSetPinValue(2,1);  // led state 
		_delay_ms(1000);
	}
	if (x<5 && flag1==0)
	{
		Buzzer_toggle();
		DIO_enuSetPinValue(2,1);  // led state 
		_delay_ms(500);
		LCD_vidSendCmd(0,LCD_CLR);
		LCD_vidSendCmd(0,LCD_LINE_1);
		LCD_vidWriteStr(0,"Stop");
	}
	uint8 p;
	if (DIO_enuReadPinValue(start,&p) == 1)
	{
		flag1=1;
		Buzzer_off();
		StepperV_ON(up);
	}
// 	Wireless Charging
// 		if (strcmp(WC,"WC,on"))
// 		{
// 			LCD_vidSendCmd(0,LCD_CLR);
// 			LCD_vidSendCmd(0,LCD_LINE_1);
// 			LCD_vidWriteStr(0,"Wireless Charging is activated");
// 			DIO_enuSetPinValue(2,1);
// 		}
}