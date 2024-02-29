

		/*----------------- Libraries and Definitions ------------*/
#include "STD_Types.h"
#include "ADC.h"
#include "LDR.h"
		
		/*--------------------- Global Variables ------------------*/

static uint16 u16LDR_ReadValue;

		/*--------------------------- Function to return the percentage of max light intensity ----------------------------------*/

uint8 LDR_Read(void)
{
	u16LDR_ReadValue= ADC_u16ReadSync();
	u16LDR_ReadValue= ((uint32)u16LDR_ReadValue*5000)/1024;
	return u16LDR_ReadValue;  
}
