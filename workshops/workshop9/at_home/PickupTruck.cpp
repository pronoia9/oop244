// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               PickupTruck.cpp
// Version:            1.0
// Date:               Nov 16, 2016            
/////////////////////////////////////////////

//#include <string>
#include <cstring>
#include "PickupTruck.h"

using namespace std;
namespace sict
{
	PickupTruck::PickupTruck()
	{
		loadAmount_ = 0;
		loadedMaterial_[0] = '\0';
	}

	void PickupTruck::load(const char * loadedMaterial, int loadAmount)
	{
		loadAmount_ = loadAmount;
		//strcpy_s(loadedMaterial_, strlen(loadedMaterial), loadedMaterial);
		strcpy(loadedMaterial_, loadedMaterial);
	}

	void PickupTruck::unload()
	{
		loadAmount_ = 0;
	}

	bool PickupTruck::isEmpty() const
	{
		return loadAmount_ == 0;
	}

	void PickupTruck::accelerate()
	{
		speed(speed() + 20);
	}

	void PickupTruck::brake()
	{
		if (speed() > 5)
			speed(speed() - 5);
		else
			speed(0);
	}

	std::ostream & PickupTruck::display(std::ostream & ostr) const
	{
		//clog << "[INFO]  PickupTruck::display(std::ostream & ostr)" << endl;
		if (isEmpty())
			ostr << "This pickup truck is not carrying any load";
		else
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;

		if (speed() > 0)
			ostr << ", traveling at the speed of " << speed() << " km/h.";
		else
			ostr << " and is parked.";

		return ostr;
	}
}