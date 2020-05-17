#include <drivers/rover_bmp280_barometer_driver.h>
#include <middleware/rover_bmp280_barometer_middleware.h>
#include <type.h>
#include <global.h>

RoverBMP280Barometer::RoverBMP280Barometer(){

}

RoverBMP280Barometer::RoverBMP280Barometer(pin_t CSpin, pin_t MOSIpin, pin_t MISOpin, pin_t SCKpin){
    CS = CSpin;
    MOSI = MOSIpin;
    MISO = MISOpin;
    SCK = SCKpin;
    // TODO need  
    bmp = Adafruit_BMP280(CS, MOSI, MISO, SCK);

    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

    while(!bmp.begin())
    {
        /* There was a problem detecting the BNO055 ... check your connections */
        while(1)
        {
            #if DEBUG
                Serial.print("Ooops, no BMP280 detected ... Check your wiring or I2C ADDR!\n");
            #endif
        }
    }
    starting_altitude = GetAltitude() + DELTA_HEIGHT_THRESHOLD;
    takeoff_altitude = GetAltitude();
    start_landing_detection = false;
    Serial.println("BMP initialized");
}

//returns altitude in metres
double RoverBMP280Barometer::GetAltitude(){
    return current_altitude;
}

void RoverBMP280Barometer::UpdateAltitude(){
    current_altitude = bmp.readAltitude(1013.25); 
    Serial.println(current_altitude);
}
