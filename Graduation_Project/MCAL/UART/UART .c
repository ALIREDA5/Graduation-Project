#include "STD_Types.h"
#include "BIT_MATH.h"

#include "USART.h"
#include "USART_cfg.h"
#include "USART_priv.h"


pf USART_pfRxFunc ;
pf USART_pfTxFunc ;
pf USART_pfUDRFunc ;


void USART_vidInit(void)
{
	uint8 u8UCSRCLoc =0b10000000;
	u8UCSRCLoc |= USART_MODE << 6 ;
	u8UCSRCLoc |= USART_PARITY_MODE << 4 ;
	u8UCSRCLoc |= USART_STOP_BIT_SELECT << 3 ;
	u8UCSRCLoc |= (USART_DATA_SIZE & 0b00000011) << 1;
	u8UCSRCLoc |= USART_CLOCK_POLARITY;

	UCSRC = u8UCSRCLoc ;
	UCSRB |= (0b00011000 | (USART_DATA_SIZE & 0b00000100));
	UCSRA |= (USART_TRANSMISSION_SPEED << 1);
	UCSRA |=  USART_MULTI_PROCESSOR_COMMUNICATION_MODE;

	CLR_BIT(UBRRH,7);
	UBRRL = USART_MY_BAUD_RATE;                //16 BIT
	UBRRH = ((USART_MY_BAUD_RATE) >> 8);

}

void USART_vidEnable(void)
{
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}
void USART_vidDisable(void)
{
	CLR_BIT(UCSRB,3);
	CLR_BIT(UCSRB,4);
}

void USART_vidEnable_Receiver(void)
{
	SET_BIT(UCSRB,4);
}

void USART_vidDisable_Receiver(void)
{
	CLR_BIT(UCSRB,4);
}
void USART_vidEnable_Transmitter(void)
{
	SET_BIT(UCSRB,3);
}
void USART_vidDisable_Transmitter(void)
{
	CLR_BIT(UCSRB,3);
}

void USART_vidEnable_RX_Int(void)
{
	SET_BIT(UCSRB,7);
}
void USART_vidDisable_RX_Int(void)
{
	CLR_BIT(UCSRB,7);
}

void USART_vidEnable_TX_Int(void)
{
	SET_BIT(UCSRB,6);
}
void USART_vidDisable_TX_Int(void)
{
	CLR_BIT(UCSRB,6);
}

void USART_vidEnable_UDR_Int(void)
{
	SET_BIT(UCSRB,5);
}
void USART_vidDisable_UDR_Int(void)
{
	CLR_BIT(UCSRB,5);
}

void USART_vidSetCallBack_Rx(pf pfCallFuncRxCpy)
{
	USART_pfRxFunc = pfCallFuncRxCpy ;
}

void USART_vidSetCallBack_Tx(pf pfCallFuncTxCpy)
{
	USART_pfTxFunc = pfCallFuncTxCpy ;
}

void USART_vidSetCallBack_UDR(pf pfCallFuncUDRCpy)
{
	USART_pfUDRFunc = pfCallFuncUDRCpy ;
}

void USART_Transmit(uint8 data)
{
	// Wait for empty transmit buffer
	while (!(UCSRA & (1 << 5)));

	// Put data into buffer and send
	UDR = data;
}

void USART_TransmitString(uint8* data)
{
	// Wait for empty transmit buffer
	while (*data != '\0')		/* Send string till null */
	{
		USART_Transmit(*data);
		data++;
	}
}

uint8 USART_Receive(void)
{
	// Wait for data to be received
	while (!(UCSRA & (1 << 7)));

	// Return received data
	return UDR;
}


void __vector_13 (void) __attribute__((signal,used));
void __vector_13 (void)
{
	USART_pfRxFunc();
}

void __vector_14 (void) __attribute__((signal,used));
void __vector_14 (void)
{
	USART_pfUDRFunc();
}

void __vector_15 (void) __attribute__((signal,used));
void __vector_15 (void)
{
	USART_pfTxFunc();
}