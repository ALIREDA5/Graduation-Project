
#ifndef USART_CFG_H
#define USART_CFG_H

#define FOSC                                           8000000UL

#define USART_BAUD_RATE                                USART_BAUD_115200

#define USART_MULTI_PROCESSOR_COMMUNICATION_MODE       USART_DISABLE

#define USART_TRANSMISSION_SPEED                       USART_1X          //This bit only has effect for the asynchronous

#define USART_MODE                                     USART_ASYNCHRONOUS

#define USART_PARITY_MODE                              USART_DISABLE

#define USART_STOP_BIT_SELECT                          USART_STOP_BIT_1

#define USART_DATA_SIZE                                USART_DATA_SIZE_8_BIT

#define USART_CLOCK_POLARITY                           USART_XCK_RISING_TX_XCH_FALLING_RX



/************************/
#if ((USART_MODE    ==   USART_ASYNCHRONOUS) && (USART_TRANSMISSION_SPEED == USART_1X))
#define USART_MY_BAUD_RATE       (((FOSC/(USART_BAUD_RATE * 16UL)))-1)

#elif ((USART_MODE    ==   USART_ASYNCHRONOUS) && (USART_TRANSMISSION_SPEED == USART_2X))
#define USART_MY_BAUD_RATE       (((FOSC/(USART_BAUD_RATE * 8)))-1)

#elif ((USART_MODE    ==   USART_SYNCHRONOUS) && (USART_TRANSMISSION_SPEED == USART_1X))
#define USART_MY_BAUD_RATE       (((FOSC/(USART_BAUD_RATE * 2)))-1)

#endif


#endif
