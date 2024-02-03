#ifndef TIM0_H
#define TIM0_H

#include "../../Lib/STD_Types.h"

void TIM0_vidInit(void) ;

void TIM0_vidEnableOvfInt(void);
void TIM0_vidDisableOvfInt(void);

void TIM0_vidEnableCmpInt(void);
void TIM0_vidDisableCmpInt(void);

void TIM0_SetTimVal(uint8 u8TimValCpy);
void TIM0_SetOutputCmpVal(uint8 u8OutputCmpValCpy);

void TIM0_vidSetCallBackOvf(pf pfovfFunCpy);
void TIM0_vidSetCallBackCmp(pf pfCmpFunCpy);
void TIM0_vidSetCallBackCmp1(pf pfCmpFunCpy, uint32 timein_ms);

#endif
