/*
 * SPI_slave_test.c
 *
 * Created: 3/2/2024 4:20:59 PM
 *  Author: Ali Reda
 */ 



/*

#include "stdint.h"
#include "MCAL/SPI.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "Utils.h"
*/
/*
int main(void)
{
	sei();
	Init_Pins();
	LCD_Init();
	SPI_slave_init();
	uint8_t data = 'k';
	
	// this method use interrupt to receive data 
	SPI_recieve_setcallback(&data);
	SPI_interrupt_enable();
	while (1)
	{
		
		LCD_GOTO(0,1);
		LCD_WriteChar(data);
		
		// this method use periodic check which lead to lose of data
		// 		if (SPI_recieve_PC(&data))
		// 		{
		// 			LCD_GOTO(0,1);
		// 			LCD_WriteChar(data);
		// 		}
	}
*/