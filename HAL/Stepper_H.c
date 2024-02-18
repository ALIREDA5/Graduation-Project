/*
 * Stepper_M.c
 *
 * Created: 10/26/2023 1:17:29 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/
#include "avr/delay.h"
#include "STD_Types.h"
#include "DIO.h"
#include "TIM2.h"

#include "Stepper_H.h"

/*----------------- Functions Definitions ------------*/
/*------------------------- Function Definition of stepper motor to turn only one turn -----------------------------*/

void tog(void)
{
	uint8 Vlue;
	DIO_enuReadPinValue(STEP , &Vlue);

	if (Vlue == 1 )
	{
		DIO_enuSetPinValue(STEP,0);
	}
	else
	{
		DIO_enuSetPinValue(STEP,1);
	}
}

/*------------------------- Function Definition of stepper motor to turn only one turn -----------------------------*/
void StepperH_ON(uint8 direction)
{
	// Full_Step:
	/*DIO_enuSetPinValue(MS1,0);
	DIO_enuSetPinValue(MS2,0);
	DIO_enuSetPinValue(MS3,0);*/
	DIO_enuSetPinValue(EN,0);



	if (direction == CW)
	{
		DIO_enuSetPinValue(DIR , 1);
	}
	else if (direction == CCW)
	{
		DIO_enuSetPinValue(DIR , 0);
	}

	for(uint16 i=0; i < 15000; i++)
	{

		DIO_enuSetPinValue(STEP , 1);
		_delay_us(700);
		DIO_enuSetPinValue(STEP , 0);
		_delay_us(150);
	}
	_delay_ms(500);


	/*switch(d)
	{
	case right:
		DIO_enuSetPinValue(dir,1);
		break;
	case left:
		DIO_enuSetPinValue(dir,0);
		break;
	}
	DIO_enuSetPinValue(enable,1);
	for (uint8_t i=0; i<(200); i++)
	{
		TIMER2_SetInterrupt_ms(0.1,tog);
	}*/
}

/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
void StepperH_off()
{
	DIO_enuSetPinValue(EN,0);
}

/*void Stepper_ON(uint8 u8direction , uint16 u16Angle)
{
	uint32 NumOfSteps = (u16Angle * 200ul ) / 360 ;
	uint32 NumOfItirations = NumOfSteps / 4 ;
	uint32 u16Cntr ,  u16Cntr1;
	uint8 u8Step = 0 , Direction ;

	Direction = u8direction;
	if ( Direction == CW)
	{
		for (u16Cntr = 0 ; u16Cntr < NumOfItirations ; NumOfItirations++)
		{
			for ( u16Cntr1 = 0 ; u16Cntr1 < 4 ; u16Cntr1++)
			{
				if (u16Cntr1 == u8Step)
				{
					DIO_enuSetPinValue(STEPPERFIRSTPIN + u16Cntr1 , 0);
				}
				else
				{
					DIO_enuSetPinValue(STEPPERFIRSTPIN + u16Cntr1 , 1);
				}
			}
			_delay_ms(100 );
			u8Step++;
		}
	}
	else if ( Direction == CCW)
	{
		for (u16Cntr = 0 ; u16Cntr < NumOfItirations ; NumOfItirations++)
		{
			for ( u16Cntr1 = 4 ; u16Cntr1 > 0 ; u16Cntr1--)
			{
				if (u16Cntr1 == u8Step)
				{
					DIO_enuSetPinValue(STEPPERFIRSTPIN + u16Cntr1 , 0);
				}
				else
				{
					DIO_enuSetPinValue(STEPPERFIRSTPIN + u16Cntr1 , 1);
				}
			}
			_delay_ms(200);
			u8Step++;
		}
	}

}

 */

/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
/*void Stepper_off(void)
{
	uint8 u8Cntr1;
	for ( u8Cntr1 = 0 ; u8Cntr1 < 4 ; u8Cntr1 ++)
	{
		DIO_enuSetPinValue(STEPPERFIRSTPIN + u8Cntr1 , 1);
	}
}
 */
