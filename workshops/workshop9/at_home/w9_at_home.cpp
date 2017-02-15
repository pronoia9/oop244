#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"
#include "Driver.h"

using namespace std;
using namespace sict;

int main()
{
	SportCar tesla(240, 2);
	PickupTruck ford;
	Driver john("John", tesla);
	Driver kim("Kim", ford);
	//clog << endl << "[INFO] - cout << tesla" << endl;
	cout << tesla << endl;
	//clog << endl << "[INFO] - cout << ford" << endl;
	cout << ford << endl;

	ford.load("Bricks", 3500);
	//clog << endl << "[INFO] - john.drive()" << endl;
	john.drive();
	//clog << endl << "[INFO] - kim.drive()" << endl;
	kim.drive();
	//clog << endl << "[INFO] - john.stop()" << endl;
	john.stop();
	//clog << endl << "[INFO] - kim.stop()" << endl;
	kim.stop();
	//clog << endl << "[INFO] - cout << tesla" << endl;
	cout << tesla << endl;
	//clog << endl << "[INFO] - cout << ford" << endl;
	cout << ford << endl;

	return 0;
}

/*
[INFO] - cout << tesla
This sport car is carrying 2 passengers and is parked.

[INFO] - cout << ford
This pickup truck is not carrying any load and is parked.

[INFO] - john.drive()
John is driving this car.
This sport car is carrying 2 passengers and is traveling at a speed of 30 km/h.

[INFO] - kim.drive()
Kim is driving this car.
This pickup truck is carrying 3500 kgs of Bricks, traveling at the speed of 15 km/h.

[MISSING] John is driving this car.
This sport car is carrying 2 passengers and is parked.

[MISSING] Kim is driving this car.
This pickup truck is carrying 3500 kgs of Bricks and is parked.

[MISSING] This sport car is carrying 2 passengers and is parked.
[MISSING] This pickup truck is carrying 3500 kgs of Bricks and is parked.
*/