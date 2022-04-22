#ifndef __ACTIVITY_2_H_
#define __ACTIVITY_2_H_

#define voltage_ref_value (REFS0) //For Aref=AVcc
#define ADC_enable (ADEN) //to enable ADC
#define ADC_channel_select (ADMUX) //for channel selection
#define ADC_prescalar (ADPS0)  //These bits determine the division factor between the system clock frequency and the input clock to the ADC.
#define ADC_status (ADCSRA)  //ADC Control and Status Register A
#define ADC_start_conversion (ADSC)  // enable to start ADC conversion
#define ADC_conversion_finish (ADIF) //enables interrupt flag when conversion is completed
#define initial_read_value (0)       // initial value from which conversion start
#define ADC_channel_select_value (0xf8) //11111000 for analog channel selection
#define ADC_channel_value (0b00000111)  //ADC Channel must be 0-7

/**
 * Include files
 */ 
#include "activity_1.h"

/**
 * Function Definitions
 */

/**
 * @brief Initialize ADC and set prescalar for voltage reference value
 * 
 */
void InitADC(void);
/**
 * @brief Read analog value and starts to convert to corresponding digital value from the specified ADC channel
 * 
 * @param[in] ADC_channel from which analog value is read, channels vary from 0 to 7 so it is unsigned int of 8 bit
 *
 *@return a 16 bit unsigned int as it is 10 bit resolution
 */
uint16_t ReadADC(uint8_t ADC_channel);
/**
 * @brief function where the code execution starts
 */
uint16_t activity_2(void);

#endif /** __ACTIVITY_2_H_ */
