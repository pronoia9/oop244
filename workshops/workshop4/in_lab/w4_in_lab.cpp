// OOP244 Workshop 4:	Constructors
// File:				w4_in_lab.cpp
// Version:				1.0
// Date:				2/8/2016
// Author:				Fardad Soleimanloo
// Description:
// This file tests in-lab section of your workshp
/////////////////////////////////////////////

#include <iostream>
#include "Enrollment.h"
#include "Enrollment.h"  // this is on purpose

using namespace std;
using namespace ict;

void displayEnrollments(const Enrollment& e1, const Enrollment& e2);

int main()
{
	// constructors
	Enrollment e1("College English", "EAC150", 2015, 1, 5);
	Enrollment e2, e3;
	Enrollment badData[] = 
	{
		Enrollment("Intro to Programming in C", "IPC144", 2015, 1, 5),
		Enrollment((char*)0, "IPC144", 2015, 1, 5),
		Enrollment("Intro to Programming in C", (char*)0, 2015, 1, 5),
		Enrollment("", "IPC144", 2015, 1, 5),
		Enrollment("Intro to Programming in C", "", 2015, 1, 5),
		Enrollment("Intro to Programming in C", "IPC144", 2014, 1, 5),
		Enrollment("Intro to Programming in C", "IPC144", 2015, 0, 5),
		Enrollment("Intro to Programming in C", "IPC144", 2015, 4, 5),
		Enrollment("Intro to Programming in C", "IPC144", 2015, 1, 0)
	};

	cout << "Testing Enrollment objects" << endl << endl;

	// testing two invalid Enrollments
	displayEnrollments(e3, e2);

	// testing isValid and inisValid Enrollments
	displayEnrollments(e1, e2);

	// setting the second one to OOP244
	e2.set("Object Oriented Programming", "OOP244", 2015, 1, 5);

	displayEnrollments(e1, e2);

	// setting the enrollment to true;
	e2.set("Object Oriented Programming", "OOP244", 2015, 1, 5, true);

	displayEnrollments(e1, e2);

	// removing conflict;
	e2.set("Object Oriented Programming", "OOP244", 2015, 1, 6);

	displayEnrollments(e1, e2);

	// making sure all the conditions are met for an inisValid Enrollment.
	cout << endl << "Only index 0 should be isValid:" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << "index: " << i << " - " << (badData[i].isValid() ? "V" : "Not v") << "alid." << endl;
	}

	return 0;

}
void displayEnrollments(const Enrollment& e1, const Enrollment& e2)
{
	cout << "----------------------------------------------" << endl;
	e1.display();
	cout << (e1.isEnrolled() ? "E" : "Not e") << "nrolled" << endl;
	e2.display();
	cout << endl << "There is " << (e1.hasConflict(e2) ? "" : "not ") << "a conflict!" << endl;
}