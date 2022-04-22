#include "activity_1.h"
#include <avr/io.h>
/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
    /* Configure LED Pin as output */
    LED_OUTPUT |= (1 <<LED_OUTPUT_PIN);
    /* Configure switch pins as input */
    SWITCH_INPUT&=~(1<<BUTTON_SENSOR_SWITCH);
    SWITCH_PORT|=(1<<BUTTON_SENSOR_SWITCH);

    SWITCH_INPUT&=~(1<<HEATER_SWITCH);
    SWITCH_PORT|=(1<<HEATER_SWITCH);
}
/**
 * @brief Function to change state of the LED
 * 
 * @param[in] state 8 bit unsigned int
 * 
 */
void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}
/**
 * @brief checks the state of the switches
 * 
 * @return int
 */
int check_switch_state(void)
{   return ((!(SWITCH_PIN&(1<<BUTTON_SENSOR_SWITCH))) && (!(SWITCH_PIN&(1<<HEATER_SWITCH))));
}
/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void delay_ms(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}
/**
 * @brief function where the code execution starts
 * 
 */
void activity_1(void)
{
	/* Initialize Peripherals */
	peripheral_init();

	while(1)
	{   
        if(check_switch_state()) /* if both switches are closed LED will turn ON */
        {
        change_led_state(LED_ON);
		delay_ms(LED_ON_TIME);
        }
        else
        {
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
        }	
	}
}
