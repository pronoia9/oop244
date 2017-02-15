// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               Driver.h
// Version:            1.0
// Date:               Nov 16, 2016      
/////////////////////////////////////////////

#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_

#include "Car.h"

namespace sict
{
	class Driver
	{
	private:
		// private members go here
		char name_[31];
		Car& car_;

	public:
		// public members go here
		//Driver();
		Driver(const char* name, Car& theCar);
		void drive();
		void stop();
		void showStatus();
	};
}

#endif