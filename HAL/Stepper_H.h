/*
 * Stepper_M.h
 *
 * Created: 10/26/2023 1:17:49 AM
 *  Author: Ali Reda
 */ 


#ifndef STEPPER_H_H_
#define STEPPER_H_H_

	/*----------------- Libraries and Definitions ------------*/

#define EN     16
#define STEP   17
#define DIR    18
#define MS1    19
#define MS2    20
#define MS3    21

typedef enum
{
	right=0,
	left
}direction;

#define CW   0 
#define CCW  1
#define STEPPERFIRSTPIN 16
	/*--------------------- Stepper Motor Functions Prototypes ---------------------------*/
	
void StepperH_ON(uint8 direction);
void Stepper_off();


#endif /* STEPPER_M_H_ */
