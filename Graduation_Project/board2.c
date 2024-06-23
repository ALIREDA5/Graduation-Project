
#define  F_CPU 8000000UL
#include "MCAL/DIO/DIO.h"
#include "MCAL/Timer1/TIM1.h"
#include "MCAL/SPI/SPI.h"
#include "HAL/Stepper_V.h"
#include "HAL/LCD.h"
#include "Sensors/Ultrasonic_Sensor.h"
#include "APP/APP.h"

uint8 u8ServoState;
uint8 u8Mode;
uint8 u8Pos;

void recieve()
{
	uint8 num = SPI_u8RecvData();
	// num --> 23
	u8Pos = num % 10;	// pos --> 3
	u8Mode = num / 10;   // Mode  --> 2 
}

int main(void)
{
	DIO_vidInit();
	SPI_vidInit();
	ULTRASONIC_Init();
	SPI_vidSetCallBack(recieve);
    while (1) 
    {
		US_module();
		uint8 u8StartButton;
		DIO_enuReadPinValue(3,&u8StartButton);  // pin A3 --> start button
		if (u8StartButton==1)
		{
			if (u8Mode == 1)
			{
				Park(u8Pos);
			}
			else if (u8Mode == 2)
			{
				Take_out(u8Pos);
			}
		}
		
    }
}


