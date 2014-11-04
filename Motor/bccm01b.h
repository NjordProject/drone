/*
Bccm01b.h - Library for controlling motor.
Created by Njord team, November 3, 2014.
*/

#ifndef Bccm01b_h
#define Bccm01b_h

#include "Arduino.h"

//Class representing one motor
class Bccm01b {
	public:
		Bccm01b (int pin); //Constructor
		int controlSpeed (int value); //Setter speed
		int reportSpeed (); //Getter speed
		int getPin(); //Getter pin
	private:
		int _pin;
		int _value; //Speed
};

#endif
