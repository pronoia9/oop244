// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               SportCar.cpp
// Version:            1.0
// Date:               Nov 16, 2016      
/////////////////////////////////////////////

#include "SportCar.h"

using namespace std;
namespace sict
{
	SportCar::SportCar()
	{
		noOfPassengers_ = 0;
	}

	SportCar::SportCar(int maxSpeed, int passengers) : Car(maxSpeed)
	{
		noOfPassengers_ = passengers;
	}

	void SportCar::accelerate()
	{
		speed(speed() + 40);
	}

	void SportCar::brake()
	{
		if (speed() > 10)
			speed(speed() - 10);
		else
			speed(0);
	}

	std::ostream & SportCar::display(std::ostream & ostr) const
	{
		//clog << "[INFO]  SportCar::display(std::ostream & ostr)" << endl;
		if (speed() > 0)
		{
			ostr << "This sport car is carrying " << noOfPassengers_ <<
				" passengers and is traveling at a speed of " << speed() << " km/h.";
		}
		else if (speed() == 0)
		{
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
		}
		return ostr;
	}
}