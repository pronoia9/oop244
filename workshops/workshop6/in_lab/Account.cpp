// OOP244 Workshop 6: operators
// File:              Account.cpp
// Version:           1.0
// Date:              20/10/2016
/////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Account.h"

using namespace std;

namespace ict
{
    void Account::display(bool gotoNewline)const
	{
        cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }

    Account::Account()
	{
        name_[0] = 0;
        balance_ = 0;
    }

    Account::Account(double balance)
	{
        name_[0] = 0;
        balance_ = balance;
    }

	Account::Account(const char name[], double balance)
	{
		strcpy(name_, name);
		balance_ = balance;
	}

	Account & Account::operator += (const Account & other)
	{
		this->balance_ += other.balance_;
		return *this;
	}

	Account & Account::operator = (const char name[])
	{
		strcpy(this->name_, name);
		return *this;
	}

	Account operator + (const Account & acc, const Account & other)
	{
		Account temp;
		temp.balance_ = acc.balance_ + other.balance_;
		return temp;
	}

	std::ostream & operator << (std::ostream & out, const Account & acc)
	{
		acc.display(false);
		return out;
	}
}