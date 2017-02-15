// OOP244 Workshop 11: Function Templates
// File:               validate.h
// Version:            1.0
// Date:               Dec 3, 2016       
/////////////////////////////////////////////

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_

#include "Car.h"
#include <cstring>

namespace sict
{
	template <typename T>
	bool validate(T min, T max, T* arr, int size, bool* results)
	{
		bool check = true;

		for (int i = 0; i < size; i++)
		{
			results[i] = (arr[i] >= min && arr[i] <= max);
			if (!results[i]) { check = false; }
		}

		return check;
	}

	bool validate(char min, char max, char* arr, int size, bool* results)
	{
		bool check = true;

		for (int i = 0; i < size; i++)
		{
			results[i] = (toupper(arr[i]) >= min && toupper(arr[i]) <= max);
			if (!results[i]) { check = false; }
		}

		return check;
	}

	bool validate(Car min, Car max, Car* arr, int size, bool* results)
	{
		bool check = true;

		for (int i = 0; i < size; i++)
		{
			results[i] = (arr[i] >= min && arr[i] <= max && strlen(arr[i]) == 6);
			if (!results[i]) { check = false; }
		}

		return check;
	}
}

#endif