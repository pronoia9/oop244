// OOP244 Workshop 6: operators
// File:              Account.h
// Version:           1.0
// Date:              28/10/2016
/////////////////////////////////////////////

#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict {
	class Account
	{
	private:
		char name_[41];
		double balance_;

	public:
		// Functions
		void display(bool gotoNewline = true)const;
		void editBalance(double num);
		double getBalance() const;
		const char * getName();

		// Constructs
		Account();
		Account(double balance);
		Account(const char name[], double balance = 0.0);

		// Operator Overloads
		Account& operator += (const Account& other);
		Account& operator = (const char name[]);
	};

	// Helper Operators
	std::ostream& operator << (std::ostream& out, const Account& acc);
	double operator += (double& num, const Account& acc);
	Account operator + (const Account& acc, const Account& acc2);
};

#endif