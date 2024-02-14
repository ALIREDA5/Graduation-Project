#include <avr/delay.h>
#include "STD_Types.h"
#include "DIO.h"
#include "ADC.h"

#include "LCD.h"
#include "Buzzer.h"

#include "SMOKE.h"


void SmokeRun(void)
{

	uint8 SmokeReadVal ; 
	DIO_enuReadPinValue(SMOKEPIN , &SmokeReadVal);

	LCD_vidSendCmd(0,LCD_LINE_1 + 2);

	if (SmokeReadVal == 1  )
	{
		Buzzer_on();
		LCD_vidWriteString(0 , "SMOKE DETECTED!!");
	}

	else
	{
		Buzzer_off();
		LCD_vidWriteString(0 , "No SMOKE");
	}
}