/*
 * touchscreen.h
 *
 *  Created on: 2 окт. 2018 г.
 *      Author: danilbogdanov
 */

#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

#include <stdbool.h>

/*** Redefine if necessary ***/

// Warning! Use SPI bus with < 1.3 Mbit speed, better ~650 Kbit to be save.
#define ILI9341_TOUCH_SPI_PORT hspi1
extern SPI_HandleTypeDef ILI9341_TOUCH_SPI_PORT;

#define ILI9341_TOUCH_IRQ_Pin       GPIO_PIN_5
#define ILI9341_TOUCH_IRQ_GPIO_Port GPIOC
#define ILI9341_TOUCH_CS_Pin        GPIO_PIN_4
#define ILI9341_TOUCH_CS_GPIO_Port  GPIOC

// change depending on screen orientation
#define ILI9341_TOUCH_SCALE_X 320
#define ILI9341_TOUCH_SCALE_Y 240


// call before initializing any SPI devices
void ILI9341_TouchUnselect();
void ILI9341_TouchSelect();
void ILI9341_TouchInit();
bool ILI9341_TouchPressed();
uint16_t ILI9341_TouchGetX();
uint16_t ILI9341_TouchGetY();
#endif /* TOUCHSCREEN_H_ */
