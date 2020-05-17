#ifndef ROVER_IR_H
#define ROVER_IR_H

#include <type.h>
#define SENSOR_VOLTAGE_SCALING 0.0048828125

class RoverIR{
    public:
        RoverIR();

        RoverIR(pin_t ir_port);
        /**
         * 
         */ 
        int AttachIr(pin_t ir_port);
        /**
         * get the sensor distance reading in (cm).
         */ 
        int GetIrDistance();

    private:
        pin_t port;
        int distance;
};

#endif
