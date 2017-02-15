// OOP244 Workshop 5: Classes with resources
// File:        Contact.h
// Version:     1.0
// Date:        10/13/16
/////////////////////////////////////////////

#include "Contact.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
namespace ict {

	void Contact::read()
	{
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << noPN_ << " phone numbers: " << endl;
		for (int i = 0; i < noPN_; i++)
		{
			cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}

	bool Contact::isEmpty() const
	{
		return phoneNumber_ == nullptr;
	}

	void Contact::display() const
	{
		//cout << "DEBUG! display()" << endl;
		cout << name_ << endl;
		for (int i = 0; i < noPN_; i++)
		{
			phoneNumber_[i].PhoneNumber::display(true);
		}
		cout << "----------------------------------------" << endl;
	}

	void Contact::setEmpty()
	{
		name_[0] = 0;
		noPN_ = 0;
		phoneNumber_ = nullptr;
	}

	Contact::Contact()
	{
		//cout << "DEBUG! Contact()" << endl;
		setEmpty();
	}

	Contact::Contact(const char * name, int noPN)
	{
		//cout << "DEBUG! Contact(2 parameters)" << endl;
		phoneNumber_ = new PhoneNumber[noPN];
		//int len = strlen(name);
		if (strlen(name) > 40)
		{
			//strcpy(name_, "Testing the contact with a looooong name");
			strncpy(name_, name, 40);
			name_[40] = '\0';
		}
		else
		{
			strcpy(name_, name);
		}
		noPN_ = noPN;
	}

	Contact::~Contact()
	{
		//cout << "DEBUG! ~Contact()" << endl;
		if (nullptr != this->phoneNumber_)
		{
			delete[] this->phoneNumber_;
			this->phoneNumber_ = nullptr;
		}
	}

	void Contact::copy(const Contact & source)
	{
		if (source.isEmpty()) // if other/copy code is empty
		{
			this->setEmpty(); // set the current obj into empty state
		}
		else
		{
			// shallow copy
			strcpy(this->name_, source.name_);
			this->noPN_ = source.noPN_;

			// allocate new memory
			phoneNumber_ = new PhoneNumber[this->noPN_];
			for (int i = 0; i<this->noPN_; i++)
			{
				this->phoneNumber_[i] = source.phoneNumber_[i];
			}
		}
	}

	Contact::Contact(Contact & source)
	{
		this->copy(source);
	}

	Contact & Contact::operator=(const Contact & source)
	{
		if (this != &source)
		{
			delete[] this->phoneNumber_;
			this->copy(source);
		}
		
		return *this;
	}
}