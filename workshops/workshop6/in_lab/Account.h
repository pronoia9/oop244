// OOP244 Workshop 6: operators
// File:              Account.h
// Version:           1.0
// Date:              20/10/2016
/////////////////////////////////////////////

#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

namespace ict
{
   class Account
   {
   private:
      char name_[41];
      double balance_;

   public:
      void display(bool gotoNewline = true)const;
      Account();
      Account(double balance);
      Account(const char name[], double balance = 0.0);
	  Account& operator += (const Account& other);
	  Account& operator = (const char name[]);
	  friend Account operator + (const Account& acc, const Account& other);
   };   
   std::ostream& operator << (std::ostream& out, const Account& acc);
};

#endif