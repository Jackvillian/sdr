/*
 * lcd-tft.h
 *
 *  Created on: 30 сент. 2018 г.
 *      Author: danilbogdanov
 */

#ifndef LCD_TFT_H_
#define LCD_TFT_H_

#include "font.h"
#include <stdbool.h>

#endif /* LCD_TFT_H_ */
#define TFT_RESET_PIN GPIO_PIN_8
#define TFT_RESET_PORT GPIOD
#define TFT_DC_PIN    GPIO_PIN_9
#define TFT_DC_PORT GPIOD
#define TFT_CS_PIN    GPIO_PIN_12
#define TFT_CS_PORT GPIOB

#define TFT_DC_SET    GPIO_SetBits(GPIOD, TFT_DC_PIN);
#define TFT_DC_RESET  GPIO_ResetBits(GPIOD, TFT_DC_PIN);

#define TFT_RST_SET   GPIO_SetBits(GPIOD, TFT_RESET_PIN);
#define TFT_RST_RESET GPIO_ResetBits(GPIOD, TFT_RESET_PIN);

#define TFT_CS_SET    GPIO_SetBits(GPIOB, TFT_CS_PIN);
#define TFT_CS_RESET   GPIO_ResetBits(GPIOB, TFT_CS_PIN);

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04
// default orientation
#define ILI9341_WIDTH  240
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR)
// Color definitions
#define	ILI9341_BLACK   0x0000
#define	ILI9341_BLUE    0x001F
#define	ILI9341_RED     0xF800
#define	ILI9341_GREEN   0x07E0
#define ILI9341_CYAN    0x07FF
#define ILI9341_MAGENTA 0xF81F
#define ILI9341_YELLOW  0xFFE0
#define ILI9341_WHITE   0xFFFF
#define ILI9341_COLOR565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

void ILI9341_Unselect();

void ILI9341_Init(void);
void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_WriteString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor);
void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ILI9341_InvertColors(bool invert);
