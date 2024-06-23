
#define  F_CPU 8000000UL
#include "Lib/STD_Types.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/Timer1/TIM1.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/UART/UART .h"
#include "HAL/Servo.h"
#include "HAL/Buzzer.h"
#include "HAL/LCD.h"
#include "Sensors/Flame Sensor.h"
#include "Sensors/LDR.h"
#include "APP/APP.h"

uint8 u8ServoState;
uint8 u8Mode;
uint8 u8Pos;

void recieve()
{
	uint8 num = USART_Receive();
	// num --> 123
	u8ServoState = num / 100;  // servo state 1 
	u8Pos = num % 100;	// pos --> 3
	num = num / 10;
	u8Mode = num % 10;   // Mode  --> 2 
}

int main(void)
{
	DIO_vidInit();
	USART_voidInit();
	USART_vidEnable();
	SPI_vidInit();
	USART_vidSetCallBack_Rx(recieve);
	USART_vidEnable_RX_Int();
	GIE_vidEnable();


	
	uint8 u8SentData=u8Mode*10+u8Pos;
	uint8 flag=0;
	uint8 u8WCButton;
	uint8 u8GateButton;
    while (1) 
    {
		Servo_module(u8ServoState);
		SPI_vidSendData(u8SentData);
		uint8 u8FlameValue=Flame_Read(5);  // pin A5
		if (u8FlameValue==1)
		{
			Buzzer_on();
		}
		else if (u8FlameValue==0)
		{
			Buzzer_off();
		}
		uint8 u8LDRValue=LDR_Read(0); // pin A0
		if (u8LDRValue==1)
		{
			DIO_enuSetPinValue(1,1);	// pin A1
		}
		else if (u8LDRValue==0)
		{
			DIO_enuSetPinValue(1,0);
		}
		
		DIO_enuReadPinValue(8,&u8WCButton);  // pin B0
		if (u8WCButton==0 && flag==0)
		{
			DIO_enuSetPinValue(7,1);  // pin A7
			flag=1;
		}
		else if (u8WCButton==0 && flag==1)
		{
			DIO_enuSetPinValue(7,1);
			flag=0;
		}
		DIO_enuReadPinValue(9,&u8GateButton); // pin B1
		if (u8GateButton==0)
		{
			u8ServoState=0;
			Servo_module(&u8ServoState);
		}	
    }
}
