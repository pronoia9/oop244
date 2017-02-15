// OOP244 Workshop 6: operators
// File:              Account.cpp
// Version:           1.0
// Date:              28/10/2016
/////////////////////////////////////////////

#include <iomanip>
#include <cstring>
#include "Account.h"

using namespace std;

namespace ict
{
	/*** Functions ***/
    void Account::display(bool gotoNewline)const
	{
        cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }

	void Account::editBalance(double num)
	{
		this->balance_ = num;
	}

	double Account::getBalance() const
	{
		//cout << "DEBUG : this balance = " << this->balance_ << endl;
		return this->balance_;
	}

	const char * Account::getName()
	{
		return this->name_;
	}

	
	/*** Constructs ***/
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


	/*** Operator Overloads ***/
	Account & Account::operator+=(const Account & other)
	{
		this->balance_ += other.balance_;
		return *this;
	}

	Account & Account::operator=(const char name[])
	{
		strcpy(this->name_, name);
		return *this;
	}


	/*** Helper Operators ***/
	std::ostream & operator<<(std::ostream & out, const Account & acc)
	{
		acc.display(false);
		return out;
	}

	double operator+=(double& num, const Account & acc)
	{
		num += acc.getBalance();
		return num;
	}

	Account operator+(const Account & acc1, const Account & acc2)
	{
		Account temp;
		double tempB = acc1.getBalance() + acc2.getBalance();
		temp.editBalance(tempB);
		return temp;
	}
}





/*
For main's  A = B += C += 100.01;
cout << "DEBUG START" << endl;
cout << "A= ";
A.display(1);
cout << "B= ";
B.display(1);
cout << "C= ";
C.display(1);
A = B += C += 100.01;
cout << "A= ";
A.display(1);
cout << "B= ";
B.display(1);
cout << "C= ";
C.display(1);
cout << "DEBUG END" << endl;
*/