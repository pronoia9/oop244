// OOP244 Workshop 4:	Constructors
// File:				Enrollment.h
// Version:				1.0
// Date:				10/08/2016
/////////////////////////////////////////////

#ifndef ICT_ENROLLMENT_H_
#define ICT_ENROLLMENT_H_

namespace ict
{
	class Enrollment
	{
	private:
		char name_[30 + 1];
		char code_[10 + 1];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;

	public: // from in_lab
		bool isEnrolled() const;
		bool isValid()const;
		void setEmpty();
		void display(bool nameOnly = false) const;
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
		Enrollment();
		Enrollment(const char* name, const char* code, int year, int semester, int time);

	public: // new in at_home
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);
	};
}

#endif