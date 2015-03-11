#ifndef GYRO_LIB_H
#define GYRO_LIB_H

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        #include <Wire.h>
    #endif
#else
    #include "ArduinoWrapper.h"
#endif



class Gyro {
public:
        float ypr[3]; 
	int initialise();
	int* fct_loop();
};

#endif
