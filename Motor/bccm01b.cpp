/*
Bccm01b.h - Library for controlling motor.
Created by Njord team, November 3, 2014.
*/

#include "bccm01b.h"

Bccm01b::Bccm01b (int pin) {
	_pin = pin;
	_value = 0;
	pinMode (_pin, OUTPUT);
}

int Bccm01b::controlSpeed (int value) {
	if (value < 0 || value > 255) {
		return 1;
	} else {
		_value = value;
		analogWrite (_pin, _value);
		return 0;
	}
}