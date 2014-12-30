/*
Bccm01b.h - Library for controlling motor.
Created by Njord team, November 3, 2014.
*/

#ifndef Bccm01b_h
#define Bccm01b_h

//#include "Arduino.h"
#include <stdint.h>

//Class representing one motor
class Bccm01b {
	public:
		Bccm01b ( uint8_t pin ); //Constructor
		int controlSpeed ( int value ); //Setter speed
		int reportSpeed (); //Getter speed
		const uint8_t getPin (); //Getter pin
	private:
		const uint8_t _pin;
		int _value; //Speed
};

#endif
