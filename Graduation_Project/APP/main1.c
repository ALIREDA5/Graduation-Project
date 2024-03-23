/*
 * Graduation_Project.c
 *
 * Created: 1/25/2024 9:26:57 PM
 * Author : Ali Reda
 */ 
#define  F_CPU 8000000UL
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer1/TIM1.h"
#include "../MCAL/UART/UART .h"
#include "../HAL/Servo.h"
#include "../HAL/Buzzer.h"
#include "../HAL/Stepper_V.h"
#include "../HAL/LCD.h"
#include "../Sensors/Ultrasonic_Sensor.h"
#include "APP/APP.h"

uint8 num;
uint8 servo;
uint8 state;
uint8 pos;

void recieve()
{
	 num = USART_Receive();
	// num --> 123
	uint8 n = num;
	servo = n / 100;  // servo state 1 
	pos = n % 100;	// pos --> 3
	n = n / 10;
	state = n % 10;   // state  --> 2 
}

int main(void)
{
    /* Replace with your application code */
	
	DIO_vidInit();
	USART_voidInit();
	USART_vidEnable();
	USART_vidSetCallBack_Rx(recieve);
	USART_vidEnable_RX_Int();
	GIE_vidEnable();
	USART_Transmit(num);
    while (1) 
    {
		Start(&servo);
    }
}


