#include "activity_1.h"
#include "activity_2.h"

void InitADC(void)
{
    ADC_channel_select|=(1<<voltage_ref_value); 
    ADC_status|=(1<<ADC_enable)|(7<<ADC_prescalar); 
}
uint16_t ReadADC(uint8_t ADC_channel)
{
                /* select ADC Channel ch must be 0-7*/
    ADC_channel_select&=ADC_channel_select_value; /* ADMUX=11111000 for analog channel selection*/
    ADC_channel&=ADC_channel_value; /* since ch should be between 0-7*/
    ADC_channel_select|=ADC_channel;
    /* start single conversion */
    ADC_status|=(1<<ADC_start_conversion);
    /* wait for conversion to complete */
    while(!(ADC_status & (1<<ADC_conversion_finish)));
    /* clear ADIF by writing one to it */
    ADC_status|=(1<<ADC_conversion_finish);
    return(ADC);
}
uint16_t activity_2(void)
{
    peripheral_init();
    InitADC();
    volatile uint16_t ADC_value;
    if(check_switch_state())
        {
            change_led_state(LED_ON);
		    ADC_value = ReadADC(initial_read_value);
            delay_ms(LED_ON_TIME);
        }
        else
        {
            change_led_state(LED_OFF);
		    delay_ms(LED_OFF_TIME);
        }
    return ADC_value;
}
