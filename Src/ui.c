/*
 * ui.c
 *
 *  Created on: 12 окт. 2018 г.
 *      Author: danilbogdanov
 */
#include "stm32f1xx_hal.h"
#include "touchscreen.h"
#include "font.h"
#include "lcd-tft.h"
uint8_t band=0;
uint8_t bwt=3;
uint8_t midline[45];
uint8_t freqline[45];
uint8_t graphline[100];
uint8_t footerline[100];
uint8_t amp, freq_band;
float a0,a1,a2;
uint8_t last_sel;
/*
 * void UI_SCREEN(uint8_t selector0,double freq){
	if(selector0!=last_sel){
	ILI9341_FillScreen(ILI9341_BLACK);
	last_sel=selector0;
	}
switch(selector0) {
	case 1:

        break;
	case 2:

		break;
	case 3:

	    break;

	default:
}

}*/


void UI_MAIN_SCREEN(uint8_t band,uint8_t mod[] , double bwt,double freq,float swr, uint8_t snr, uint8_t pwr){
	ILI9341_WriteString(0, 0,"[MENU] [MOD] [BAND]" , Font_16x26, ILI9341_CYAN, ILI9341_BLACK);
	for (int i=0 ; i<320;i++){
	   ILI9341_DrawPixel(i,95, ILI9341_WHITE);
	   ILI9341_DrawPixel(i,96, ILI9341_WHITE);
	   ILI9341_DrawPixel(i,97, ILI9341_WHITE);
	   }

	   sprintf(midline,"BAND:%dM MOD:%c%c%c BANDWT:%0.1lfK",band,mod[0],mod[1],mod[2],bwt);
	   sprintf(freqline,"FREQ : %.3lf KHZ",freq);
	   ILI9341_WriteString(0, 35,midline , Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	   ILI9341_WriteString(0, 65,&freqline , Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
	   UI_GRAPH(amp, freq_band,freq);
	   UI_FOOTER(swr, snr,pwr);

}
void UI_BAND_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2){
	ILI9341_WriteString(0, 0,"             [BAND]" , Font_16x26, ILI9341_RED, ILI9341_BLACK);
		    for (int i=0 ; i<320;i++){
		    		        	      ILI9341_DrawPixel(i,35, ILI9341_WHITE);
		    		        	      ILI9341_DrawPixel(i,36, ILI9341_WHITE);
		    		        	      ILI9341_DrawPixel(i,37, ILI9341_WHITE);
		    		        	      }
		    ILI9341_WriteString(0, 40,"Set Frequency Band :", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		    ILI9341_WriteString(0, 75,"[SET 160 METERS]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    ILI9341_WriteString(0, 95,"[SET 80  METERS]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    ILI9341_WriteString(0, 115,"[SET 40  METERS]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    ILI9341_WriteString(0, 135,"[SET 20  METERS]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    ILI9341_WriteString(0, 155,"[SET CB]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    for (int i=0 ; i<320;i++){
		    	    		          ILI9341_DrawPixel(i,190, ILI9341_WHITE);
		    	    		          ILI9341_DrawPixel(i,191, ILI9341_WHITE);
		    	    		          ILI9341_DrawPixel(i,192, ILI9341_WHITE);
		    	    		          }
		    ILI9341_WriteString(0, 200,"* default " , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
		    ILI9341_WriteString(0, 210,"< current " , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
}
void UI_MODULATION_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2){
	ILI9341_WriteString(0, 0,"       [MOD]" , Font_16x26, ILI9341_RED, ILI9341_BLACK);
			for (int i=0 ; i<320;i++){
			        	      ILI9341_DrawPixel(i,35, ILI9341_WHITE);
			        	      ILI9341_DrawPixel(i,36, ILI9341_WHITE);
			        	      ILI9341_DrawPixel(i,37, ILI9341_WHITE);
			        	      }
			ILI9341_WriteString(0, 40,"Set Modulation Type :", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
			ILI9341_WriteString(0, 75,"[SET FM]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		    ILI9341_WriteString(0, 95,"[SET AM]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
			ILI9341_WriteString(0, 115,"[SET USB]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
			ILI9341_WriteString(0, 135,"[SET LSB]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
			for (int i=0 ; i<320;i++){
				    	    		  ILI9341_DrawPixel(i,190, ILI9341_WHITE);
				    	    		  ILI9341_DrawPixel(i,191, ILI9341_WHITE);
				    	    		  ILI9341_DrawPixel(i,192, ILI9341_WHITE);
				    	    		  }
				    ILI9341_WriteString(0, 200,"* default " , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
				    ILI9341_WriteString(0, 210,"< current " , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
}

void UI_MENU_SCREEN(uint8_t encoder0,uint8_t encoder1,uint8_t bt0,uint8_t bt2){
	ILI9341_WriteString(0, 0,"[MENU]" , Font_16x26, ILI9341_RED, ILI9341_BLACK);
	        for (int i=0 ; i<320;i++){
	        	      ILI9341_DrawPixel(i,35, ILI9341_WHITE);
	        	      ILI9341_DrawPixel(i,36, ILI9341_WHITE);
	        	      ILI9341_DrawPixel(i,37, ILI9341_WHITE);
	        	      }
	if (encoder0 < 8){
	    ILI9341_WriteString(0, 55,"[BAND/FRQ MODE]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 75,"[BANDWIDTH]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 95,"[GRAPH MODE]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 115,"[MODULATION]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 135,"[ATTENUATION]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 155,"[GRID]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 175,"[POWER]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 195,"[AMPLIFER]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	}else if (encoder0 > 8 ){
		ILI9341_WriteString(0, 55,"[RECEIVE GAIN]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	    ILI9341_WriteString(0, 75,"[AUDIO INPUT]" , Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 95,"[AUDIO OUTPUT]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 115,"[RESET FPGA]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 135,"[CALIBRATE TOUCH]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 155,"[PARAMS DEFAULT]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 175,"[RESET TO DEFAULT]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
		ILI9341_WriteString(0, 195,"[READ MEMORY]" ,Font_11x18, ILI9341_GREEN, ILI9341_BLACK);
	}
}

void UI_FOOTER(uint8_t swr, uint8_t snr, uint8_t pwr){
	sprintf(footerline,"SWR: %.1lf SNR: %d  PWR: %dW",swr,snr,pwr);
	ILI9341_WriteString(0, 220,"SWR: 1.3   SNR: 8   PWR: 45W" , Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
}

void UI_GRAPH(uint8_t amp, uint8_t freq_band, double freq){
	for (int i=103; i<195; i++){
		   ILI9341_DrawPixel(160,i, ILI9341_RED);
		   ILI9341_DrawPixel(160,i, ILI9341_RED);

	   }
	   ILI9341_WriteString(0, 103,"-0db" , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	   ILI9341_WriteString(0, 133,"-50db" , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	   ILI9341_WriteString(0, 163,"-90db" , Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	   a0=freq-0.500;
	   a2=freq+0.500;

	   sprintf(graphline,"  %.3lf           %.3lf         %.3lf",a0,a1,a2);
	   ILI9341_WriteString(10, 200,&graphline , Font_7x10, ILI9341_GREEN, ILI9341_BLACK);
	   for (int i=0 ; i<320;i++){
	      ILI9341_DrawPixel(i,211, ILI9341_WHITE);
	      ILI9341_DrawPixel(i,212, ILI9341_WHITE);
	      ILI9341_DrawPixel(i,213, ILI9341_WHITE);
	      }
}

