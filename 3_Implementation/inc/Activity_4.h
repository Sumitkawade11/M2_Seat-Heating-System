#ifndef __ACTIVITY_4_H_
#define __ACTIVITY_4_H_


 #include "activity_1.h"

 #define BAUD_RATE_REG_L (UBRR0L) /* set baud rate*/
 #define BAUD_RATE_REG_H (UBRR0H)
 #define USART_STATUS_C (UCSR0C)  
 #define USART_STATUS_A (UCSR0A)
 #define USART_STATUS_B (UCSR0B)
 #define USART_MODE_SELECT (UMSEL00) /* SEL00 for synchronous USART */
 #define USART_CH_SIZE_01 (UCSZ01) /* Z01,Z00 are set For 8 bit */
 #define USART_CH_SIZE_00 (UCSZ00) /* character size */
 #define RECEIVER_ENABLE (RXEN0)   /* enable the receiver */
 #define TRANSMITTER_ENABLE (TXEN0)   /* enable the transmitter*/
 #define RX_COMPLETE_INTERRUPT (RXCIE0) /* enables interrupt after receiving completes */
 #define TX_COMPLETE_INTERRUPT (TXCIE0)  /* enables interrupt after transmitting completes */
 #define REG_EMPTY (UDRE0) /* checks if register is empty */
 #define BUFFER (UDR0) /* stores temporarily data */
/**
 * @brief initializes USART, sets baud rate, enables receiver and transmitter
 * 
 * @param[in] ubrr_value baud rate to be set and it is unsigned int of 16 bit
 */
 void USARTInit(uint16_t ubrr_value);
 /**
 * @brief writes character from buffer to parralel bus
 * 
 * @param[in] temperature_value which is of 16 bit
 */
 void USARTWriteChar(uint16_t temperature_value);
 /**
 * @brief  to display message
 * 
 */
 void message();
 /**
 * @brief  calls all the functions
 * 
 * @param[in] digital_value which is the adc output, is of 16 bit 
 */
 void activity_4(volatile uint16_t digital_value);
 #endif /** __ACTIVITY_4_H_ */
