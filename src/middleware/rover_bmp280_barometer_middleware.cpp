#include <middleware/rover_bmp280_barometer_middleware.h>
#include <drivers/rover_bmp280_barometer_driver.h>
#include <Arduino.h>
#include <global.h>

bool BarometerConfirmLanding(RoverBMP280Barometer *bmpObj){
    bool is_landed = false;
    double current_alt = bmpObj->GetAltitude();
    Serial.println("");
    Serial.print("current_alt = ");
    Serial.println(current_alt);

    if(bmpObj->starting_altitude - current_alt >= DELTA_HEIGHT_THRESHOLD){
        #if DEBUG
            Serial.printf("-------------------------BAROMETER LANDING CONFIRMED-----------------------------\n");
        #endif
        
        is_landed = true;
    }
    else{
        #if DEBUG
            Serial.printf("-------------------------BAROMETER LANDING DENIED--------------------------------\n");
        #endif        
    }

    return is_landed;
}
