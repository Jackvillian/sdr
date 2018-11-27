/*
 * ui.h
 *
 *  Created on: 12 окт. 2018 г.
 *      Author: danilbogdanov
 */

#ifndef UI_H_
#define UI_H_

void UI_MAIN_SCREEN(uint8_t band,uint8_t mod[] ,uint8_t vol,double freq, float swr, uint8_t snr, uint8_t pwr);
void UI_MENU_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2);
void UI_MODULATION_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2);
void UI_BAND_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2);
void UI_GRAPH_FRAME(uint8_t amp, uint8_t freq_band, double freq);
void UI_GRAPH(uint8_t amp, uint8_t freq_band, double freq);
void UI_TX(uint8_t amp, uint8_t freq_band, double freq);
void UI_FOOTER(float swr, uint8_t snr, uint8_t pwr);
void UI_DEBUG(uint32_t touchX, uint32_t touchY, uint8_t enc , uint8_t bt0, uint8_t bt1, uint8_t bt2,uint8_t adc0,uint8_t adc1);
void UI_CLEAR(void);
#endif /* UI_H_ */
