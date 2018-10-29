/*
 * grid.c
 *
 *  Created on: Oct 17, 2018
 *      Author: danilbogdanov
 */
#include "stm32f1xx_hal.h"
#include "grid.h"
uint8_t band=0;

uint8_t bandshift(double freq){
	if (freq >= 25.000 && freq <= 29.000){
	    band=11;
	         }
    if (freq >=14.000 && freq <= 14.350){
	    band=20;
    		 }
	if (freq >= 10.100 && freq <= 10.150){
	   	band=30;
	         }
	if (freq >= 7.000 && freq <= 7.200){
	   	band=40;
	         }
	if(freq >= 3.500 && freq <= 3.800){
	    band=80;
	         }
	if(freq >= 1.800 && freq <=2.000){
	    band=160;
	         }
	return band;
}
