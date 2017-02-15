// OOP244 Workshop 3: Dynamic Memory
// File		Weather.h
// Version 1.0
// Date		10/02/2016
// Description
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

// compilation safegaurds
/*Weather.h*/
#ifndef ICT_WEATHER_H_
#define ICT_WEATHER_H_

// ict namespace
namespace ict 
{
	// #define statements go here

	// class declration goes here
	// class Weather holds information about weather conditions
	class Weather 
	{
	private:
		char _date[6+1];
		double _highTemp;
		double _lowTemp;

	public:
		void set(const char*, double, double);
		void display() const;
		const char* date() const;
		double low() const;
	};
}
#endif