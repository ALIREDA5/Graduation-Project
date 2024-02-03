/*
 * To_Start.h
 *
 * Created: 1/26/2024 4:28:37 PM
 *  Author: Ali Reda
 */ 


#ifndef TO_START_H_
#define TO_START_H_

#include "../Lib/STD_Types.h"
#include "string.h"

#define  Relay  0
#define  start  1
#define  IR1    2
#define  IR2    3
#define  IR3    4
#define  IR4    5
#define  LS1    6
#define  LS2    7
#define  LS3    8

void Start(uint8 *state, uint8 *WC);
void Park(uint8 pos);
void Take_out(uint8 pos);
void safety(void);

#endif /* TO_START_H_ */