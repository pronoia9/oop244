// OOP244 Milestone 2:	error class, dynamic memory
// File:				Error.cpp
// Version:				1
// Date:				Nov 5, 2016
/////////////////////////////////////////////

#include <cstring>
#include "Error.h"

using namespace std;
namespace ict
{
	/***************************************** CONSTRUCTOS ******************************************/
	Error::Error()
	{
		//clog << "[INFO]  -  Error()" << endl;
		// Sets the message_ member variable to nullptr
		message_ = nullptr;
	}

	Error::Error(const char * Error)
	{
		//clog << "[INFO]  -  Error(const char * Error)" << endl;
		// Sets the message_ member variable to nullptr 
		message_ = nullptr;
		// and then uses the message() setter member function to set the error message to the Error argument
		message(Error);
	}

	Error::~Error()
	{
		//clog << "[INFO]  -  ~Error()" << endl;
		// de-allocates the memory pointed by message_
		clear();
	}


	/************************************ PUBLIC MEMBER FUNCTIONS ***********************************/
	void Error::clear()
	{
		//clog << "[INFO]  -  Error::clear()" << endl;
		// de-allocates the memory pointed by message_
		delete[] message_;
		// and then sets message_ to nullptr
		message_ = nullptr;
	}

	bool Error::isClear() const
	{
		//clog << "[INFO]  -  Error::isClear()" << endl;
		// returns true if message_  is nullptr
		return (nullptr == message_);
	}

	void Error::message(const char * value)
	{
		//clog << "[INFO]  -  Error::message(const char * value)" << endl;
		// de-allocating the memory pointed by message_  
		clear();
		// allocating memory to the same length of value + 1 keeping the address in message_ data member
		message_ = new char[strlen(value) + 1];
		// copying value c-string into message_
		strcpy(message_, value);
	}

	const char * Error::message() const
	{
		//clog << "[INFO]  -  Error::message()" << endl;
		// returns the address kept in message_
		return message_;
	}


	/****************************************** OPERATORS *******************************************/
	Error & Error::operator = (const char * errorMessage)
	{
		//clog << "[INFO]  -  Error::operator = (const char * errorMessage)" << endl;
		// de-allocating the memory pointed by message_  
		// & allocating memory to the same length of Error + 1 and keeping the address in message_ data member
		// & copying Error c-string into message_
		message(errorMessage);
		return *this;
	}


	/************************************** HELPER FUNCTIONS ****************************************/

	std::ostream & operator<<(std::ostream & ostr, const Error & error)
	{
		//clog << "[INFO]  -  operator << (std::ostream & ostr, const Error & error)" << endl;
		// If Error isClear,
		if (error.isClear())
		{
			//  Nothing should be printed
		}
		// otherwise,
		else
		{
			// the c-string pointed by message_ is printed
			ostr << error.message();
		}
		return ostr;
	}

}