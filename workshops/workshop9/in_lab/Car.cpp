// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               Car.cpp
// Version:            1.0
// Date:               Nov 16, 2016       
/////////////////////////////////////////////

#include "Car.h"

namespace sict
{
	void Car::speed(int value)
	{
		if (value > maxSpeed()) value = maxSpeed();
		else if (value < 0) value = 0;
		speed_ = value;
	}

	int Car::maxSpeed() const
	{
		return maxSpeed_;
	}

	int Car::speed() const
	{
		return speed_;
	}

	/*Car::Car()
	{
		speed_ = 0;
		maxSpeed_ = 0;
	}*/

	Car::Car(int maxSpeed)
	{
		speed_ = 0;
		maxSpeed_ = maxSpeed;
	}
}