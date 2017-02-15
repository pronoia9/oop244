// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               Vehicle.h
// Version:            1.0
// Date:               Nov 16, 2016     
/////////////////////////////////////////////

#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_

#include <iostream>

namespace sict
{
	// complete the declaration of the class
	class Vehicle
	{
	public:
		// public members go here
		virtual void accelerate() = 0;
		virtual void brake() = 0;
		virtual std::ostream& display(std::ostream& ostr) const = 0;
	};
}
#endif