#include <drivers/rover_bno055_imu.h>
#include <middleware/rover_bno55_imu_middleware.h>
#include <global.h>
#include <math.h>

bool IMUConfirmLanding(RoverBNO055IMU *imuObj)
{
    bool is_landed = false;
    imuObj->landed_count += IMUDetectLanding(imuObj);
    imuObj->landing_confirmation_count++;

    if (imuObj->landing_confirmation_count >= LANDING_CHECK)
    {

        if (imuObj->landing_confirmation_count == imuObj->landed_count){

        #if DEBUG
            Serial.printf("-------------------------LANDING CONFIRMED-----------------------------\n");
        #endif
            is_landed = true;
        }
        else{
        #if DEBUG
            Serial.printf("-------------------------LANDING DENIED--------------------------------\n");
        #endif
        }

        imuObj->landing_confirmation_count = 0;
        imuObj->landed_count = 0;
    }

    return is_landed;
}

bool IMUDetectLanding(RoverBNO055IMU *imuObj)
{

    double avg_accel = imuObj->GetAccelVector();

    if (fabs(avg_accel) < GRAVITY + LANDING_RANGE && fabs(avg_accel) > GRAVITY - LANDING_RANGE)
    {       
        #if DEBUG
             Serial.printf("\t\tLANDED\n");
        #endif
        return true;
    }
    else
    {
        #if DEBUG
             Serial.printf("\t\tdid not land\n");
        #endif
        return false;
    }
}
