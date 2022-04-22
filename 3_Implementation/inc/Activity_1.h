#ifndef __ACTIVITY_1_H_
#define __ACTIVITY_1_H_
/**
 * @file activity1.h
 * @author Chinmayi B C
 * @brief Project to turn ON LED connected to AVR328 MCU GPIO Pin if button sensor and heater switches are pressed
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (500)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */

#define SWITCH_PORT (PORTD) /**< Switch port */
#define SWITCH_PIN (PIND)   /**< Pin register to read INPUT */
#define BUTTON_SENSOR_SWITCH (PD0)  /**< Switch 1 for button sensor */
#define HEATER_SWITCH (PD1)  /**< Switch 2 for heater */

#define LED_OUTPUT (DDRB)  /**< Output data register */
#define LED_OUTPUT_PIN (DDB0)  /**< ouput pin */
#define SWITCH_INPUT (DDRD)  /**< input data register */

/**
 * Include files
 */ 
#include <avr/io.h>
#include <util/delay.h>

/**
 * Function Definitions
 */

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void);
/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);

/**
 * @brief  Check the state of the switches and returns INT value
 * 
 * @return INT
 */

int check_switch_state(void); 
/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void delay_ms(uint32_t delay_time);
/**
 * @brief function where the code execution starts
 */
void activity_1(void);


#endif /** __ACTIVITY_1_H_ */
