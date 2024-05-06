/*
 * To_Take_out.c
 *
 * Created: 1/26/2024 4:29:48 PM
 *  Author: Ali Reda
 */ 

#include "../HAL/Limit Switch.h"
#include "../HAL/Stepper_H.h"
#include "../HAL/Stepper_V.h"
#include "../Sensors/IR Sensor.h"
#include "APP.h"

void Take_out(uint8 u8Pos)
{
	switch(u8Pos)
	{
		case 1:
		Stepper_ON(CW,IR1,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,IR2,V);
		
		Stepper_ON(CCW,LS3,H);
		
		Stepper_ON(CCW,LS1,V);
		break;
		
		case 2:
		Stepper_ON(CW,IR2,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,IR3,V);
		
		Stepper_ON(CCW,LS3,H);
		
		Stepper_ON(CCW,LS1,V);
		break;
		
		case 3:
		Stepper_ON(CW,IR3,V);
		
		Stepper_ON(CW,5,H);
		
		Stepper_ON(CW,LS2,V);
		
		Stepper_ON(CCW,LS3,H);
		
		Stepper_ON(CCW,LS1,V);
		break;
		
		default:
		break;
	}
}