#include <avr/delay.h>
#include "../Lib/STD_Types.h"

#include "DIO.h"
#include "GIE.h"

#include "TIM1.h"
#include "US.h"

static volatile uint16 t1,t2,flag=0,u16NumofOVF=0;

static void Func_ICU(void);
static void Func_OVF(void);

void ULTRASONIC_Init(void)
{
	//you can use timer in another mode except modes using ICR as top put take care dont reset timer
	TIM1_vidInit();
	TIM1_vidSetCallBackOvf(Func_OVF);
	TIM1_vidSetCallBackCapt(Func_ICU);
	//TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED
}

uint16 ULTRASONIC_GetDistance(void)
{
	uint16 distance;
	uint16 time;
	TIM1_SetTimVal(0);
	u16NumofOVF=0;
	flag=0;
	DIO_enuSetPinValue(UltraSonicPin , 1);
	_delay_us(10);
	DIO_enuSetPinValue(UltraSonicPin,0);
	TIM1_vidChgICUMod(TIM1_ICU_RISINGEDGE);
	TIM1_vidEnableICUInt();
	GIE_vidEnable();
	////////
	while (flag<2);
	time=t2-t1+((uint32)u16NumofOVF*65535);
	distance=time/58;

	TIM1_vidDisableBICUInt();
	return distance;

}

static void Func_ICU(void)
{
	if(flag==0)
	{
		u16NumofOVF=0;
		t1=TIM1_GetICUValue();
		flag=1;
		TIM1_vidChgICUMod(TIM1_ICU_FALLINGEDGE);
	}
	else if (flag==1)
	{
		t2=TIM1_GetICUValue();
		flag=2;
		TIM1_vidChgICUMod(TIM1_ICU_RISINGEDGE);
		TIM1_vidDisableOvfInt();
		TIM1_vidDisableBICUInt();
	}
}

static void Func_OVF(void)
{
	u16NumofOVF++;
}
