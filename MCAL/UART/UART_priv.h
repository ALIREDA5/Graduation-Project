#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


/*Multi-processor Communication Mode*/
#define USART_DISABLE				            0
#define USART_ENABLE				            1
/*speed*/
#define USART_1X			                    0    //synchronous
#define USART_2X			                    1    //has effect for the asynchronous operation
/*USART Mode Select*/
#define USART_ASYNCHRONOUS		                    0
#define USART_SYNCHRONOUS 	                            1
/*Parity Mode*/
#define USART_DISABLE				            0
#define USART_EVEN_PARITY		                    2
#define USART_ODD_PARITY 		                    3
/*Stop Bit Select*/
#define USART_STOP_BIT_1	                            0
#define USART_STOP_BIT_2			            1
/*Character Size*/
#define USART_DATA_SIZE_5_BIT                               0
#define USART_DATA_SIZE_6_BIT		                    1
#define USART_DATA_SIZE_7_BIT		                    2
#define USART_DATA_SIZE_8_BIT                               3
#define USART_DATA_SIZE_9_BIT		                    7
/*Clock Polarity*/
#define USART_XCK_RISING_TX_XCH_FALLING_RX  	            0
#define USART_XCK_RISING_RX_XCH_FALLING_TX	       	1
/*Baud Rate*/
#define USART_BAUD_2400                                     2400
#define USART_BAUD_4800                                     4800
#define USART_BAUD_9600                                     9600
#define USART_BAUD_14400                                    14400
#define USART_BAUD_19200                                    19200
#define USART_BAUD_28800                                    28800
#define USART_BAUD_38400                                    38400
#define USART_BAUD_57600                                    57600
#define USART_BAUD_76800                                    76800
#define USART_BAUD_115200                                   115200
#define USART_BAUD_230400                                   230400
#define USART_BAUD_250000                                   250000
#define USART_BAUD_500000                                   500000
#define USART_BAUD_1000000                                  1000000




#define UDR             *((volatile uint8 *) 0X2C)
#define UCSRA           *((volatile uint8 *) 0X2B)
#define UCSRB           *((volatile uint8 *) 0X2A)
#define UCSRC           *((volatile uint8 *) 0X40)
#define UBRRL           *((volatile uint8 *) 0X29)
#define UBRRH           *((volatile uint8 *) 0X40)

	
#endif
