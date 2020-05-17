#ifndef _ROVER_BNO55_IMU_MIDDLEWARE_H_
#define _ROVER_BNO55_IMU_MIDDLEWARE_H_

#include <drivers/rover_bno055_imu.h>
#include <global.h>

#define LANDING_RANGE 0.2
#define GRAVITY 9.8
#define LANDING_CHECK 1000

void UpdateIMUAccelValues(void);
bool IMUConfirmLanding(RoverBNO055IMU *imuObj);
bool IMUDetectLanding(RoverBNO055IMU *imuObj);

#endif
