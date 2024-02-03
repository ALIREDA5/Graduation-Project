/*
 * Stepper_M.h
 *
 * Created: 10/26/2023 1:17:49 AM
 *  Author: Ali Reda
 */ 


#ifndef STEPPER_M_H_
#define STEPPER_M_H_

	/*----------------- Libraries and Definitions ------------*/

#define enable 9
#define step   10
#define dir    11
#define MS1    12
#define MS2    13
#define MS3    14


typedef enum
{
	right=0,
	left
}direction;
	
	/*--------------------- Stepper Motor Functions Prototypes ---------------------------*/
	
void StepperH_ON(direction d);
void StepperH_off();




#endif /* STEPPER_M_H_ */