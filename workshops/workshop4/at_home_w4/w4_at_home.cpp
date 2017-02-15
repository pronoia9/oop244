// OOP244 Workshop 4: Constructors 
// File: w4_at_home.cpp
// Version: 1.0
// Date: 2/8/2016
// Author: Fardad Soleimanloo
// Description:
// This file tests at-home section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Enrollment.h"

using namespace std;
using namespace ict;

//void displayEnrollments(const Enrollment& e1, const Enrollment& e2);

int main() 
{
	Enrollment* slots;
	Enrollment current;

	char name[31];
	char code[11];
	int year;
	int semester;
	int slot;
	int i = 0;
	int n;

	cout << "Please entere the number of course sections: ";
	cin >> n;
	cin.ignore(1000, '\n');
	slots = new Enrollment[n];
	cout << "Please enter the following " << n << " course sections for enrollment:" << endl;

	while (i < n) 
	{
		cout << "Course section " << (i + 1) << ":" << endl
			<< "Subject Name: ";
		cin.getline(name, 30, '\n');
		cout << "Subject Code: ";
		cin.getline(code, 10, '\n');
		cout << "Year: ";
		cin >> year;
		cout << "Semester: ";
		cin >> semester;
		cout << "Slot: ";
		cin >> slot;
		cin.ignore(1000, '\n');
		current.set(name, code, year, semester, slot);
		if (current.isValid()) 
		{
			int c;
			if ((c = current.enrol(slots, n)) == 0) 
			{
				char res;
				slots[i] = current;
				cout << "Enrolled!" << endl;
				i++;
				cout << "Continue? (y/n)";
				res = cin.get();
				if (res != 'y' && res != 'Y') {
					i = n;
				}
				cin.ignore(1000, '\n');
			}
			else 
			{
				cout << "There is a conflict with the following, please change enrollment time: " << endl;
				slots[c - 1].display();
			}
		}
		else 
		{
			cout << "InValid information entered, please redo: " << endl;
		}
	}
	for (i = 0; i < n; i++) 
	{
		cout << "------------------------------" << endl;
		slots[i].display();
	}

	// testing withdraw();
	slots[0].withdraw();
	slots[0].display();
	delete[] slots;

	return 0;
}