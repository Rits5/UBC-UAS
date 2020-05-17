#ifndef _ROVER_BNO055_IMU_H_
#define _ROVER_BNO055_IMU_H_

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <type.h>


class RoverBNO055IMU
{
private:
    /* data */
    Adafruit_BNO055 bno;
    pin_t SCL;
    pin_t SDA;
    sensor_t sensor;

    struct ImuAccel{
        double xAccel;
        double yAccel;
        double zAccel;
        double prevXAccel;
        double prevYAccel;
        double prevZAccel;
    };
    ImuAccel accel_vectors;

public:
    double current_heading;
    int landing_confirmation_count;
    int landed_count;
        
    RoverBNO055IMU();
    RoverBNO055IMU(pin_t SCL, pin_t SDA);

    double GetHeading();
    void UpdateHeading();

    double GetAccelVector();
};


#endif 
