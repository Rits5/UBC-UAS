#include <drivers/rover_sharp2y0a21_ir_sensor.h>
#include <Arduino.h>

RoverIR::RoverIR(){

}

RoverIR::RoverIR(pin_t ir_port){
    AttachIr(ir_port);
}

int RoverIR::AttachIr(pin_t ir_port){
    port = ir_port;
    pinMode(ir_port, INPUT);

    return 0;
}

int RoverIR::GetIrDistance(){
    float volts = analogRead(port) * SENSOR_VOLTAGE_SCALING;  // value from sensor * (5/1024)

    // TODO: avoid magic numbers
    int distance = 13*pow(volts, -1); // worked out from datasheet graph
    return distance;
}
