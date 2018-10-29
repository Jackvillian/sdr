/*
 * swr_meter.c
 *
 *  Created on: Oct 17, 2018
 *      Author: danilbogdanov
 */
#include "swr_meter.h"
#include "stm32f1xx_hal.h"
uint32_t adcResult0 = 0;
uint32_t adcResult1 = 0;
uint32_t straight_U(void){
	//HAL_ADC_ConfigChannel(&SWR_ADC, ADC_CHANNEL_0);
	//HAL_ADC_Start(&hadc1);
	//HAL_ADC_PollForConversion(&hadc1, 100);
	//adcResult0 = HAL_ADC_GetValue(&hadc1);
	//HAL_ADC_Stop(&hadc1);
	return adcResult0;
}
uint32_t reverse_U(void){
	//HAL_ADC_ConfigChannel(&SWR_ADC, ADC_CHANNEL_1);
	//HAL_ADC_Start(&hadc1);
	//HAL_ADC_PollForConversion(&hadc1, 100);
	//adcResult1 = HAL_ADC_GetValue(&hadc1);
	//HAL_ADC_Stop(&hadc1);
	return adcResult1;
}
