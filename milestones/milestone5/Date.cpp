// OOP244 Milestone 1:	iostream
// File:				Date.cpp
// Version:				1
// Date:				Nov 4, 2016
/////////////////////////////////////////////

// header files go here
#include <iomanip>
#include "Date.h" // includes <iostream>
#include "wpgeneral.h"

using namespace std;
namespace ict
{
	/*********************************** PRIVATE MEMBER FUNCTIONS ************************************/
	// returns a unique value representing the date
	// this value is used to compare two dates
	int Date::value()const
	{
		//clog << "[INFO]  -  Date::value()const" << endl;
		return year_ * 372 + mon_ * 31 + day_;
	}

	// Sets the readErrorCode_ member variable to one of the possible values
	void Date::errCode(int errorCode)
	{
		//clog << "[INFO]  -  Date::errCode(int errorCode)" << endl;
		readErrorCode_ = errorCode;
	}

	// validate() is for validation logic and setting the _readErrorCode
	void Date::validate()
	{
		//clog << "[INFO]  -  Date::validate()" << endl;
		if (MIN_YEAR <= year_ && year_ <= MAX_YEAR) // if year is valid
		{
			if (1 <= mon_ && mon_ <= 12) // and if month is valid
			{
				if (1 <= day_ && day_ <= mdays()) // and also if day is valid
				{
					errCode(NO_ERROR);
				}
				else
				{
					errCode(DAY_ERROR);
				}
			}
			else
			{
				errCode(MON_ERROR);
			}
		}
		else
		{
			errCode(YEAR_ERROR);
		}
	}


	/************************************ PUBLIC MEMBER FUNCTIONS ************************************/
	// mdays(): returns the number of days in a month based on day and year values
	// _mon value must be set for this function to work
	// if _mon is invalid, this function returns -1
	// leap years are considered in this logic
	int Date::mdays() const
	{
		//clog << "[INFO]  -  Date::mdays()" << endl;
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	// Returns the readErrorCode_ value
	int Date::errCode() const
	{
		//clog << "[INFO]  -  Date::errCode()" << endl;
		return readErrorCode_;
	}

	// Returns true if readErrorCode_ is not equal to zero
	bool Date::bad() const
	{
		//clog << "[INFO]  -  Date::bad()" << endl;
		return errCode() != NO_ERROR;
	}


	/***************************************** CONSTRUCTOS ******************************************/
	// accepts three arguments to set the values of year_, mon_ and day_ 
	// also sets the readErrorCode_ to NO_ERROR
	Date::Date()
	{
		//clog << "[INFO]  -  Date()" << endl;
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		errCode(NO_ERROR);
	}
	
	Date::Date(int year, int mon, int day)
	{
		//clog << "[INFO]  -  Date(int year, int mon, int day)" << endl;
		year_ = year;
		mon_ = mon;
		day_ = day;
		validate();
	}


	/****************************************** OPERATORS *******************************************/
	bool Date::operator==(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator == (const Date & D)" << endl;
		return this->value() == D.value();
	}

	bool Date::operator!=(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator != (const Date & D)" << endl;
		return this->value() != D.value();
	}

	bool Date::operator<(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator < (const Date & D)" << endl;
		return this->value() < D.value();
	}

	bool Date::operator>(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator > (const Date & D)" << endl;
		return this->value() > D.value();
	}

	bool Date::operator<=(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator <= (const Date & D)" << endl;
		return this->value() <= D.value();
	}

	bool Date::operator>=(const Date & D) const
	{
		//clog << "[INFO]  -  Date::operator >= (const Date & D)" << endl;
		return this->value() >= D.value();
	}

	/***************************************** IO FUNCTIONS *****************************************/
	std::istream & Date::read(std::istream & istr)
	{
		//clog << "[INFO]  -  Date::read(istream & istr)" << endl;
		errCode(NO_ERROR);
		
		istr >> year_;
		istr.ignore();
		istr >> mon_;
		istr.ignore();
		istr >> day_;

		if (istr.fail()) { errCode(CIN_FAILED); }
		//else if (MIN_YEAR > year_ || year_ > MAX_YEAR)  { errCode(YEAR_ERROR); }
		//else if (1 > mon_ || mon_ > 12)  { errCode(MON_ERROR); }
		//else if (mdays() < day_ || day_ < 1)  { errCode(DAY_ERROR); }
		else { validate(); }

		return istr;
	}

	std::ostream & Date::write(std::ostream & ostr) const
	{
		//clog << "[INFO]  -  Date::write(std::ostream & ostr)" << endl;
		ostr << right
			 << setfill('0') << setw(2) << year_ << '/'
			 << setfill('0') << setw(2) << mon_ << '/'
			 << setfill('0') << setw(2) << day_;
		
		return ostr;
	}


	/************************************ NON MEMBER OPERATORS **************************************/
	std::istream& operator >> (std::istream & istr, Date & date) /* cin >> date */
	{
		//clog << "[INFO]  -  operator >> (std::istream & istr, Date & date)" << endl;
		date.read(istr);
		return istr;
	}

	std::ostream& operator << (std::ostream & ostr, const Date & date) /* cout << date */
	{
		//clog << "[INFO]  -  operator << (std::ostream & ostr, const Date & date)" << endl;
		date.write(ostr);
		return ostr;
	}
}