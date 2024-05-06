/*
 * Stepper_M.h
 *
 * Created: 10/26/2023 1:17:49 AM
 *  Author: Ali Reda
 */ 


#ifndef STEPPER_M_H_
#define STEPPER_M_H_

	/*----------------- Libraries and Definitions ------------*/

#define EN 17
#define step   18
#define dir    16

#define CW   0
#define CCW  1
#define  H   0
#define  V   1
	
	/*--------------------- Stepper Motor Functions Prototypes ---------------------------*/
	
void Stepper_ON(uint8 u8MotorDirection,uint8 u8SensorPin,uint8 u8MovementDirection);
void Stepper_off();




#endif /* STEPPER_M_H_ */