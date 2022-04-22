#ifndef __ACTIVITY_3_H_
#define __ACTIVITY_3_H_
/**
 * @file activity3.h
 * @author Chinmayi B C
 * @brief Project to turn ON LED connected to AVR328 MCU GPIO Pin if button sensor and heater switches are pressed also read analog values from temperature sensor convert to corresponding digital values and display waveform
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 /**
 * Include files
 */ 
#include "activity_1.h"
#include "activity_2.h"

#define CONTROL_REG_A (TCCR1A)
#define CONTROL_REG_B (TCCR1B)
#define WAVEFORM_OUTPUT (DDRB)
#define WAVEFORM_OUTPUT_PIN (PB1)
#define COMPARE_OUTPUT_A (COM1A1)
#define WAVEFORM_MODE_10 (WGM10)
#define WAVEFORM_MODE_11 (WGM11)
#define WAVEFORM_MODE_12 (WGM12)
#define CLK_SELECT_10 (CS10)
#define CLK_SELECT_11 (CS11)
#define OUTPUT_COMPARE_REG (OCR1A)

/**
 * @brief configure all timer/counter registers and set non-inverting mode, fast PWM 10 bit 
 */
void pwm_config(void);
/**
 * @brief  generates waveform for each value with delay specified
 * 
 * @param[in] ADC_value which specifies the temperature value, unsigned int of 16 bit
 */
void activity_3(volatile uint16_t ADC_value);
 #endif /** __ACTIVITY_3_H_ */
