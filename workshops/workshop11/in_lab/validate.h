// OOP244 Workshop 11: Function Templates
// File:               validate.h
// Version:            1.0
// Date:               Dec 1, 2016        
/////////////////////////////////////////////

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_

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
}

#endif