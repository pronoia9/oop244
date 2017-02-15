#include <iostream>
#include <cstring>
#include <iomanip>
#include "Weather.h"
using namespace std;
using namespace ict;
double findLow(const char* date, const Weather* data, int dataSize);

int main()
{
	int i; //  loop counter
	int n; //the count of days worth of weather
		   // initialize the weather pointer here
	Weather* weather;

	cout << "Weather Data" << endl
		<< "=====================" << endl
		<< "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocate dynamic memory here
	weather = new Weather[n];

	for (i = 0; i < n; i++)
	{
		char date_description[7];
		double high;
		double low;

		// ... add code to accept the user input for the weather array 
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

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	// accept user input for the date to find (in this example stored in char query[7])
	// and display the found low temprature.
	cin.getline(query, 7, '\n') >> query;
	// cin.getline(query, 7, '\n'); by itself wont get any input

	double low = findLow(query, weather, n);
	cout << "Low temperature: " << low << endl;

	// deallocate dynamic memory here
	delete[] weather;

	return 0;
}

double findLow(const char * date, const Weather * data, int dataSize)
{
	for (int i=0; i<dataSize; i++)
	{
		if (strcmp(date, data[i].date()) == 0)
		{
			return data[i].low();
		}
	}
	return 0.0;
}