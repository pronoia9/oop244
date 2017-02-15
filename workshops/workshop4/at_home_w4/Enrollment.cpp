// OOP244 Workshop 4: Constructors
// File:              Enrollment.cpp
// Version:           1.0
// Date:              10/08/2016
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Enrollment.h"

using namespace std;
using namespace ict;

//done
bool Enrollment::isValid()const
{
	return name_ && name_[0];
}

//done
void Enrollment::setEmpty()
{
	name_[0] = 0;
	code_[0] = 0;
	year_ = 0;
	semester_ = 0;
	slot_ = 0;
	enrolled_ = false;
}

// done
bool Enrollment::isEnrolled() const
{
	return enrolled_;
}

// done
void Enrollment::display(bool nameOnly)const
{
	if (isValid())
	{
		cout << name_;
		if (!nameOnly)
		{
			cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
			cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
		}
	}
	else
	{
		cout << "Invalid enrollment!" << endl;
	}
}

void Enrollment::set(const char * name, const char * code, int year, int semester, int time, bool enrolled)
{
	// i cant use isValid if i dont set the name_ first
	if ((name != NULL) && (name != nullptr) && (name[0] != 0) &&
		(code != NULL) && (code != nullptr) && (code[0] != 0) &&
		(year >= 2015) && (semester > 0) && (semester < 4) && (time > 0) && (time < 6))
	{
		strcpy(name_, name);
		strcpy(code_, code);
		year_ = year;
		semester_ = semester;
		slot_ = time;
		enrolled_ = enrolled;
	}
	else
	{
		setEmpty();
	}
}

bool Enrollment::hasConflict(const Enrollment & other) const
{
	if (isValid() && other.isValid() &&
		(year_ == other.year_) && (semester_ == other.semester_) && (slot_ == other.slot_))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Enrollment::Enrollment()
{
	setEmpty();
}

Enrollment::Enrollment(const char * name, const char * code, int year, int semester, int time)
{
	set(name, code, year, semester, time);
}

void Enrollment::withdraw()
{
	enrolled_ = false;

	//cout << "withdraw output" << endl;
}

int Enrollment::enrol(const Enrollment * enrollments, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (hasConflict(enrollments[i]))
		{
			return i + 1;
		}
	}

	enrolled_ = true;

	return 0;
}