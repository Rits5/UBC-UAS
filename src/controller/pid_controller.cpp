#include <controller/pid_controller.h>
#include <global.h>
#include <stdlib.h>
#include <Arduino.h>

double HeadingPIDController(double current_heading, double target_heading){
    
    PIDVariables motorPID;
    long long int delta_t = millis() - motorPID.last_time;

    double turn_angle;
    motorPID.error = target_heading - current_heading;
    motorPID.proportional = motorPID.error * K_P;
    motorPID.derivative = (motorPID.error - motorPID.prev_error) * K_D;
    motorPID.integral += motorPID.error * delta_t * K_I;
    motorPID.prev_error = motorPID.error;

    if(motorPID.error > GLOBAL::INTEGRAL_ACTIVE_ZONE){
        motorPID.integral = 0;
    }

    turn_angle = target_heading - current_heading;
    motorPID.last_time = millis();

    if((turn_angle) > 180){
        turn_angle -= 360;
    }else if (turn_angle < -180) {
        turn_angle += 360;
    }
    return turn_angle;
}

void PIDinit(PIDVariables* pid){
    pid->error = 0;
    pid->proportional = 0;
    pid->derivative = 0;
    pid->integral = 0;
    pid->prev_error = 0;
}


