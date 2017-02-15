// OOP244 Milestone 2:	error class, dynamic memory
// File:				Error.h
// Version:				1
// Date:				Nov 5, 2016
/////////////////////////////////////////////

#ifndef SICT_ERROR_H__
#define SICT_ERROR_H__

#include <iostream>

namespace ict
{
	class Error
	{
	private:
		char* message_;  // x

	public:
		// constructors & destructors
		Error();
		Error(const char* Error);
		Error(const Error& em) = delete;
		virtual ~Error();
		// member functions
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message() const;
		// operators
		Error& operator = (const Error& em) = delete;
		Error& operator = (const char* errorMessage);
	};
	// helper operator
	std::ostream& operator << (std::ostream& ostr, const Error& error);
}

#endif