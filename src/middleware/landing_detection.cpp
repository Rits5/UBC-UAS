#include <middleware/rover_bmp280_barometer_middleware.h>

bool StartLandingDetection(RoverBMP280Barometer *bmpObj){
    double current_alt = bmpObj->GetAltitude();
    
    if (fabs(current_alt - bmpObj->takeoff_altitude) > DELTA_HEIGHT_THRESHOLD){
        bmpObj->start_landing_detection = true;
        #if DEBUG
            Serial.printf("-------------------------BEGIN LANDING DETECTION-----------------------------\n");
        #endif
    }
    else{
        #if DEBUG
            Serial.printf("-------------------------NOT STARING LANDING DETECTION-----------------------------\n");
        #endif
    }

    return bmpObj->start_landing_detection;
}
