/*
 * grid.h
 *
 *  Created on: Oct 17, 2018
 *      Author: danilbogdanov
 */

#ifndef GRID_H_
#define GRID_H_

#include <string.h>
#include <stdarg.h>
#include <stdbool.h>



#define M11START 25.000
#define M11STOP  29.000
#define M11STEP  10.0
#define M20START 14.000
#define M20STOP  14.350
#define M20STEP  2.9

double bandshift(double freq, bool bandrfq);

#endif /* GRID_H_ */
