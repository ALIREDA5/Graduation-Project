/*
 * To_Start.c
 *
 * Created: 1/26/2024 4:28:22 PM
 *  Author: Ali Reda
 */ 

#include <avr/delay.h>
#include "../Lib/STD_Types.h"
#include "../HAL/LCD.h"
#include "../Sensors/Ultrasonic_Sensor.h"


void US_module()
{
	// ultrasonic sensor
	uint16 u16USValue= ULTRASONIC_GetDistance();
	if (u16USValue>5 && u16USValue<10);
	{
		while(1)
		{
			DIO_vidTogglePin(28);  // led state
			_delay_ms(1000);
			if (u16USValue<5)
			{
				DIO_vidTogglePin(28);  // led state
				_delay_ms(500);
				LCD_vidSendCmd(0,LCD_CLR);
				LCD_vidSendCmd(0,LCD_LINE_1);
				LCD_vidWriteStr(0,"Stop");
			}
			if (u16USValue==3)
			{
				break;
			}
		}
		
	}
	
}