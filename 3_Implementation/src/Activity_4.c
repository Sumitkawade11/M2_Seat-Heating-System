#include"activity_4.h"
void USARTInit(uint16_t ubrr_value)
{
    BAUD_RATE_REG_L = ubrr_value;
    BAUD_RATE_REG_H = (ubrr_value>>8)&0x00ff;
    USART_STATUS_C = (1<<USART_MODE_SELECT)|(1<<USART_CH_SIZE_01)|(1<<USART_CH_SIZE_00);
    USART_STATUS_B=(1<<RECEIVER_ENABLE)|(1<<TRANSMITTER_ENABLE)|(1<<RX_COMPLETE_INTERRUPT)|(1<<TX_COMPLETE_INTERRUPT);
}

void message()
{
    int i;
    unsigned char display_msg[] = "Temperature(in degree Celsius)="; 
        i = 0;
        while(display_msg[i] != 0)
        {
            while (!( USART_STATUS_A & (1<<REG_EMPTY)));
            BUFFER  = display_msg[i];            
            i++;                             /*increment counter*/
        }
}
void USARTWriteChar(uint16_t temperature_value)
{
    if((temperature_value>=0)&&(temperature_value<=200))
    {
        message();
        unsigned char display_temperature[] = "20"; /* 20% duty cycle*/
        int j = 0;
        while(display_temperature[j] != 0) 
        {
            while (!( USART_STATUS_A & (1<< REG_EMPTY))); 
            BUFFER  = display_temperature[j];            
            j++;                             /*increment counter*/
        }
    }
    else if(temperature_value>=210 && temperature_value<=500)
    {
        message();
        unsigned char display_temperature[] = "25"; /* 40% duty cycle */
        int j = 0;
        while(display_temperature[j] != 0)
        {
            while (!( USART_STATUS_A & (1<< REG_EMPTY))); 
            BUFFER = display_temperature[j];            
            j++;                             /*increment counter*/
        }
    }
    else if(temperature_value>=510 && temperature_value<=700)
    {
        message();
        unsigned char display_temperature[] = "29"; /* 70% duty cycle */
        int j = 0;
        while(display_temperature[j] != 0)
        {
            while (!( USART_STATUS_A & (1<< REG_EMPTY))); 
            BUFFER  = display_temperature[j];           
            j++;                             /*increment counter*/
        }
    }
    else if(temperature_value>=710 && temperature_value<=1024)
    {
        message();
        unsigned char display_temperature[] = "33"; /* 95% duty cycle */
        int j = 0;
        while(display_temperature[j] != 0) 
        {
            while (!( USART_STATUS_A & (1<< REG_EMPTY))); 
            BUFFER  = display_temperature[j];           
            j++;                             /*increment counter*/
        }
    }
    else
    {
        unsigned char display_msg[] = "Invalid input";  /*100% duty cycle*/
        int k = 0;
        while(display_msg[k] != 0) 
        {
            while (!( USART_STATUS_A & (1<< REG_EMPTY)));
            BUFFER  = display_msg[k];            
            k++;                             /*increment counter*/
        }
    }
    while (!( USART_STATUS_A & (1<< REG_EMPTY)));   
		 BUFFER  = '\n';   /* new line */

}
void activity_4(volatile uint16_t digital_value)
{
    USARTInit(103);
    USARTWriteChar(digital_value);
}
