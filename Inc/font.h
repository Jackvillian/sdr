/*
 * font.h
 *
 *  Created on: 1 окт. 2018 г.
 *      Author: danilbogdanov
 */

#ifndef FONT_H_
#define FONT_H_

#include <stdint.h>

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

#endif /* FONT_H_ */
