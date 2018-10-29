/*
 * swr_meter.h
 *
 *  Created on: Oct 17, 2018
 *      Author: danilbogdanov
 */

#ifndef SWR_METER_H_
#define SWR_METER_H_
#include <stdint.h>
#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_adc.h"
//#define SWR_ADC hadc1
//extern ADC_ChannelConfTypeDef ADC_CHANNEL_0;
//extern ADC_ChannelConfTypeDef ADC_CHANNEL_1;
//extern ADC_HandleTypeDef SWR_ADC;

uint32_t straight_U(void);
uint32_t reverse_U(void);

#endif /* SWR_METER_H_ */
