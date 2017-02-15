// OOP244 Workshop 3: Dynamic Memory
// File		w3_in_lab.cpp
// Version 1.0
// Date		10/02/2016
// Description
// This file is used to demonstrate dynamic memory in
// C++ and to process an array of objects of compound
// type where the user specifies the number of
// elements in the array at run-time.
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Weather.h"
using namespace std;

int main() 
{
	int i; //  loop counter
	int n; //the count of days worth of weather
		   // initialize the weather pointer here
	ict::Weather* weather;

	cout << "Weather Data" << endl
		<< "=====================" << endl
		<< "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocate dynamic memory here
	weather = new ict::Weather[n];

	for (i = 0; i < n; i++) 
	{
		char date_description[7];
		double high;
		double low;

		// ... add code to accept the user input
		// for the weather array
		cout << left << setfill(' ') << setw(10) << "Enter date" << ": ";
		cin >> date_description;

		cout << left << setfill(' ') << setw(10) << "Enter high" << ": ";
		cin >> high;

		cout << left << setfill(' ') << setw(10) << "Enter low" << ": ";
		cin >> low;

		weather[i].set(date_description, high, low);
	}

	cout << endl
		<< "Weather report:" << endl
		<< "Date        high  low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++) 
	{
		weather[i].display();
	}

	// deallocate dynamic memory here
	delete[] weather;

	return 0;
}