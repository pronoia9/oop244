// OOP244 Workshop 5: Classes with resources
// File: PhoneNumber.cpp
// Version: 1.0
// Date: 2016/02/15
// Author: Fardad Soleimanloo
/////////////////////////////////////////////

#ifndef ICT_PHONENUMBER_H_
#define ICT_PHONENUMBER_H_

namespace ict
{
	class PhoneNumber
	{
	private:
		int area_;
		int number_;
		char* type_;

		// FUNCTIONS
	private:
		void setEmpty();
		bool isValid(int area, int number, const char* type) const;
		bool allocateAndCopy(int area, int number, const char* str);

	public:
		void read();  // Performs a fool-proof entry of phone number form console
		void display(bool goToNewLine = true) const;  // displays the phone number and goes to new line
		bool isEmpty()const;
		// constructors & destructors
		PhoneNumber();
		PhoneNumber(const PhoneNumber& cp);
		~PhoneNumber();
		// operators
		PhoneNumber& operator=(const PhoneNumber& ro);
	};
}

#endif