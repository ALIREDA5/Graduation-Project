
#ifndef USART_H
#define USART_H

void USART_voidInit (void);
void USART_vidEnable(void);
void USART_vidDisable(void);
void USART_vidEnable_Receiver(void);
void USART_vidDisable_Receiver(void);
void USART_vidEnable_Transmitter(void);
void USART_vidDisable_Transmitter(void);
void USART_vidEnable_RX_Int(void);
void USART_vidDisable_RX_Int(void);
void USART_vidEnable_TX_Int(void);
void USART_vidDisable_TX_Int(void);
void USART_vidEnable_UDR_Int(void);
void USART_vidDisable_UDR_Int(void);
void USART_vidSetCallBack_Rx(pf pfCallFuncRxCpy);
void USART_vidSetCallBack_Tx(pf pfCallFuncTxCpy);
void USART_vidSetCallBack_UDR(pf pfCallFuncUDRCpy);
void USART_Transmit(uint8 data);
void USART_TransmitString(uint8* data);
uint8 USART_Receive(void);
#endif
