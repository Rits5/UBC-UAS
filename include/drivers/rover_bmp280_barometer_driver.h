#ifndef _ROVER_BMP280_BAROMETER_H_
#define _ROVER_BMP280_BAROMETER_H_

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <utility/imumaths.h>
#include <type.h>


class RoverBMP280Barometer{
    private:
        Adafruit_BMP280 bmp;
        pin_t CS;
        pin_t MOSI;
        pin_t MISO;
        pin_t SCK;
    
    public:
        double starting_altitude;
        double current_altitude;

        double takeoff_altitude;
        bool start_landing_detection;
        
        RoverBMP280Barometer();
        RoverBMP280Barometer(pin_t CSpin, pin_t MOSIpin, pin_t MISOpin, pin_t SCKpin);

        double GetAltitude();
        void UpdateAltitude();
};

#endif
