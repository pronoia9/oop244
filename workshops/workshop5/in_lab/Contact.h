// OOP244 Workshop 5: Classes with resources
// File:        Contact.h
// Version:     1.0
// Date:        10/13/16
/////////////////////////////////////////////

#include "PhoneNumber.h"

#ifndef ICT_CONTACT_H_
#define ICT_CONTACT_H_

namespace ict
{
	class Contact
	{
	private:
		char name_[41];
		PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();

	public:
		void read();
		bool isEmpty()const;
		Contact();
		Contact(const char* name, int noPN);
		~Contact();
		void display() const;
	};
}

#endif // !ICT_CONTACT_H_

