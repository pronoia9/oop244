// OOP244 Workshop 9:  Inheritance and Virtual Functions
// File:               Driver.cpp
// Version:            1.0
// Date:               Nov 17, 2016     
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Driver.h"

using namespace std;
namespace sict
{
	Driver::Driver(const char * name, Car & theCar) : car_(theCar)
	{
		strcpy(name_, name);
	}

	void Driver::drive()
	{
		//clog << "[INFO]  Driver::drive()" << endl;
		car_.accelerate();
		car_.brake();
		this->showStatus();
	}

	void Driver::stop()
	{
		//clog << "[INFO]  Driver::stop()" << endl;
		while (car_.speed() > 0)
			car_.brake();
		this->showStatus();
	}

	void Driver::showStatus()
	{
		//clog << "[INFO]  Driver::showStatus()" << endl;
		cout << name_ << " is driving this car." << endl;
		cout << car_ << endl;
	}
}
