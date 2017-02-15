// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               SportCar.h
// Version:            1.0
// Date:               Nov 16, 2016    
/////////////////////////////////////////////

#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_

#include "Car.h"

namespace sict
{
	// complete the declaration of the class
	class SportCar : public Car
	{
	private:
		// private members go here
		int noOfPassengers_;

	public:
		// public members go here
		SportCar();
		SportCar(int maxSpeed, int passengers);
		
		// pure virtual members from base class go here
		void accelerate();
		void brake();
		std::ostream& display(std::ostream& ostr) const;
	};
}
#endif