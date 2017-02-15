// OOP244 Workshop 3: Dynamic Memory
// File		Weather.cpp
// Version 1.0
// Date		10/02/2016
// Description
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

/*Weather.cpp*/
//  includes go here
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Weather.h"
using namespace std;

// ict namespace
namespace ict
{
	// set
	void Weather::set(const char* date, double highTemp, double lowTemp)
	{
		strcpy(_date, date);
		_highTemp = highTemp;
		_lowTemp = lowTemp;
	}

	// display
	void Weather::display() const
	{
		cout << left << setfill('_') << setw(10) << _date;

		cout << right << setfill('_') << fixed << setprecision(1) << setw(6) << _highTemp;	

		cout << right << setfill('_') << fixed << setprecision(1) << setw(6) << _lowTemp << endl;
	}

	const char * Weather::date() const
	{
		return _date;
	}

	double Weather::low() const
	{
		return _lowTemp;
	}
}