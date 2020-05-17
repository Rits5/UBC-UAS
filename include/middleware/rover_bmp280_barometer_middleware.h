#ifndef _ROVER_BMP280_MIDDLEWARE_H_
#define _ROVER_BMP280_MIDDLEWARE_H_

#include <drivers/rover_bmp280_barometer_driver.h>
#include <global.h>

#define DELTA_HEIGHT_THRESHOLD 30

bool BarometerConfirmLanding(RoverBMP280Barometer *bmpObj);

#endif
