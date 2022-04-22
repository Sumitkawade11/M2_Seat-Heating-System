#include "activity_3.h"
void pwm_config(void)
{
    CONTROL_REG_A|=(1<<COMPARE_OUTPUT_A)|(1<<WAVEFORM_MODE_11)|(1<<WAVEFORM_MODE_10); /* non-inverting mode is set, fast PWM 10 bit */
    CONTROL_REG_B|=(1<<WAVEFORM_MODE_12)|(1<<CLK_SELECT_11)|(1<<CLK_SELECT_10); /* clk/64 prescalar */
    WAVEFORM_OUTPUT|=(1<<WAVEFORM_OUTPUT_PIN); /* waverform output */
}
void activity_3(volatile uint16_t ADC_value)
{
    pwm_config();
    if((ADC_value>=0) && (ADC_value<=200))
    {
       OUTPUT_COMPARE_REG=0xCD; /* 20% duty cycle */ 
    }
    else if((ADC_value>=210) && (ADC_value<=500))
    {
        OUTPUT_COMPARE_REG=0x19A; /* 40% duty cycle*/
    }
    else if((ADC_value>=510) && (ADC_value<=700))
    {
        OUTPUT_COMPARE_REG=0x2CD; /* 70% duty cycle */
    }
    else if((ADC_value>=710) && (ADC_value<=1024))
    {
        OUTPUT_COMPARE_REG=0x3CD; /* 95% duty cycle */
    }
    else
    {
        OUTPUT_COMPARE_REG=0X3FF; /* 100% duty cycle */
    }
    
}
