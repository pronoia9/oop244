// OOP244 Workshop 2: Compound types and privacy
// File w2_in_lab.cpp
// Version 1.0
// Date			2016/10/01
// Description
// This file is used to demonstrate classes in C++ and
// how member variables can be defined as private but
// accessed through member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name Date Reason
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict 
{
	// member functions' (methods') definition go here

	void AccountNumber::name(const char name[])
	{
		strcpy(_name, name);
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber)
	{
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;

		if ((MIN_BANKCODE <= bankCode && bankCode <= MAX_BANKCODE) &&
			(MIN_BRANCHCODE <= branchCode && branchCode <= MAX_BRANCHCODE) &&
			(MIN_ACCNO <= accountNumber && accountNumber <= MAX_ACCNO))
		{
			_validAccNumber = true;
		}
		else
		{
			_validAccNumber = false;
		}
	}

	void AccountNumber::display(bool display_name, bool display_number) const
	{
		if (isValid())
		{
			if ((display_name == true) && (display_number == true)) // display()
			{
				//cout << "DEBUG: isValid && display()" << endl;
				cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
			}
			else if ((display_name == false) && (display_number == true)) // display(false)
			{
				//cout << "DEBUG: isValid && display(false)" << endl;
				displayNumber();
				cout << endl;
			}
			else if ((display_name == true) && (display_number == false)) // display(true, false)
			{
				//cout << "DEBUG: isValid && display(true, false)" << endl;
				displayName();
				cout << endl;
			}
			else if ((display_name == false) && (display_number == false)) // display(false, false)
			{
				//cout << "DEBUG: isValid && display(false, false)" << endl;
				;
			}
		}
		else if (!isValid())
		{
			//cout << "DEBUG: !isValid" << endl;
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	bool AccountNumber::isValid() const
	{
		return _validAccNumber;
	}

	void AccountNumber::displayName() const
	{
		cout << "Name: " << _name;
	}

	void AccountNumber::displayNumber() const
	{
		cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
	}
}