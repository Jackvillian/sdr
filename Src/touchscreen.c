/*
 * touchscreen.c
 *
 *  Created on: 2 окт. 2018 г.
 *      Author: danilbogdanov
 */
#include "stm32f1xx_hal.h"
#include "touchscreen.h"


#define READ_X 208
#define READ_Y 0x90
void ILI9341_TouchSelect() {
    HAL_GPIO_WritePin(ILI9341_TOUCH_CS_GPIO_Port, ILI9341_TOUCH_CS_Pin, GPIO_PIN_RESET);
}

void ILI9341_TouchUnselect() {
    HAL_GPIO_WritePin(ILI9341_TOUCH_CS_GPIO_Port, ILI9341_TOUCH_CS_Pin, GPIO_PIN_SET);
}

bool ILI9341_TouchPressed() {
    return HAL_GPIO_ReadPin(ILI9341_TOUCH_IRQ_GPIO_Port, ILI9341_TOUCH_IRQ_Pin) == GPIO_PIN_RESET;
}


void ILI9341_TouchInit() {
	uint8_t a[]={0};
	a[0]=128;
	HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT,(uint8_t *)&a,1,HAL_MAX_DELAY);
}

uint16_t ILI9341_TouchGetX() {
        ILI9341_TouchSelect();
        uint8_t a[]={0};
        a[0]=211;
        uint8_t d0[1]={0},dr=0;
        uint16_t result=0;
        HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT,(uint8_t *)&a,1,HAL_MAX_DELAY);
        //HAL_Delay(1);
        HAL_SPI_Receive(&ILI9341_TOUCH_SPI_PORT,&d0,2,HAL_MAX_DELAY);
        ILI9341_TouchUnselect();
        result=d0[0];
        result<<=4;
        result|=(d0[1]>>4);
        return result;
}
uint16_t ILI9341_TouchGetY() {
        ILI9341_TouchSelect();
        uint8_t a[]={0};
        a[0]=147;
        uint8_t d0[1]={0},dr;
        uint16_t result=0;
        HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT,(uint8_t *)&a,1,HAL_MAX_DELAY);
        //HAL_Delay(1);
        HAL_SPI_Receive(&ILI9341_TOUCH_SPI_PORT,&d0,2,HAL_MAX_DELAY);
        ILI9341_TouchUnselect();
        result=d0[0];
        result<<=4;
        result|=(d0[1]>>4);
        return result;
}

