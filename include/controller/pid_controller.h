#ifndef _PID_CONTROLLER_H_
#define _PID_CONTROLLER_H_

#include <Arduino.h>

#define DELTA_T 20.0

struct PIDVariables{
    int error;
    float proportional;
    float derivative;
    float integral;
    float prev_error = 0;
    long long int last_time = millis();
};

/**
 * @param current_heading - heading between -180 to 180 degree
 * @param target_heading - heading between -180 to 180 degree
 * @return turn_angle 
 * 
 */ 
double HeadingPIDController(double current_heading, double target_heading);

#endif
