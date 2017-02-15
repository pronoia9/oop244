// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               Car.h
// Version:            1.0
// Date:               Nov 16, 2016      
/////////////////////////////////////////////

#ifndef SICT_CAR_H_
#define SICT_CAR_H_

#include "Vehicle.h"

namespace sict
{
	// complete the declaration of the class
	class Car : public Vehicle
	{
	private:
		// private members go here
		int speed_;
		int maxSpeed_;

	protected:
		// protected members go here
		void speed(int value);
		int maxSpeed() const;

	public:
		// public members go here
		int speed() const;
		//Car();
		Car(int maxSpeed = 100);
	};
}

#endif