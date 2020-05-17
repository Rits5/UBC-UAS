#include <drivers/rover_bno055_imu.h>
#include <type.h>
#include <global.h>

RoverBNO055IMU::RoverBNO055IMU(){

}

RoverBNO055IMU::RoverBNO055IMU(pin_t inputSCL, pin_t inputSDA){
    SCL = inputSCL;
    SDA = inputSDA;
    // TODO need  
    bno = Adafruit_BNO055(55, 0x28);
    bno.getSensor(&sensor);
    while(!bno.begin())
    {
        /* There was a problem detecting the BNO055 ... check your connections */
        while(1)
        {
            #if DEBUG
                Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!\n");
            #endif
        }
    }
    bno.setExtCrystalUse(true);
    current_heading = 0;
    landed_count = 0;
    landing_confirmation_count = 0;
}


double RoverBNO055IMU::GetHeading(){
    return current_heading;
}

void RoverBNO055IMU::UpdateHeading(){
    sensors_event_t event; 

    bno.getEvent(&event);

    imu::Vector<3> acc = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

    current_heading = euler.x();

    accel_vectors.xAccel = acc.x();
    accel_vectors.yAccel = acc.y();
    accel_vectors.zAccel = acc.z();  

    //Serial.printf("accel_vector = %f\n", accel_vector);
}

double RoverBNO055IMU::GetAccelVector(void){      
    return sqrt(pow(accel_vectors.xAccel, 2) + pow(accel_vectors.yAccel, 2) + pow(accel_vectors.zAccel, 2));
}
