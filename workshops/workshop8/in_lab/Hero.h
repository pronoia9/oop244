// OOP244 Workshop 8:  Derived Classes
// File:               Hero.h
// Version:            1.0
// Date:               Nov 8, 2016     
/////////////////////////////////////////////

#ifndef HERO_H
#define HERO_H

#include <iostream>

class Hero
{
private:
	char* _name;
	double _strength;
public:
	// CONSTRUCTORS
	Hero();
	Hero(const char* name, double strength);
	~Hero();
	// MEMBER FUNCTIONS
	bool isEmpty() const;
	double getStrength() const;
	void setEmpty();
	void clear();
	// I/O FUNCTIONS
	void display(std::ostream& ostr) const;
	// OPERATOR OVERLOADS
	void operator -= (double strength);
	void operator += (double strength);
};
// HELPER FUNCTIONS
bool operator < (const Hero& hero, const Hero& other);

#endif