/*
 * grid.c
 *
 *  Created on: Oct 17, 2018
 *      Author: danilbogdanov
 */
#include "stm32f1xx_hal.h"
#include "grid.h"

extern uint8_t band;
double bandshift(double freq, bool bandrfq){
	if (freq > 14.350 && freq <= 25.000 && bandrfq==true){
	         	    band=11;
	         	    freq=freq+24.0;
	         }
	   if (freq > 7.200 && freq <= 14.000 && bandrfq==true){
	      	    band=20;
	      	    freq=freq+13.0;
	      }
	   if (freq > 7.000 && freq <= 10.100 && bandrfq==true){
	   	       band=30;
	   	       freq=freq+9.0;
	   }
	   if (freq > 3.800 && freq <= 7.200 && bandrfq==true){
	   		   band=40;
	   		   freq=freq+6.0;
	   }
	   if(freq > 2.000 && freq <= 3.800 && bandrfq==true){
	   		   band=80;
	   		   freq=freq+3.5;
	   }
	   if(freq > 0.100 && freq <= 1.800 && bandrfq==true){
	      		   band=160;
	      		   freq=freq+1.8;
	   }
	   if (bandrfq==false){
	     band=0;
	     }
	return freq;
}
