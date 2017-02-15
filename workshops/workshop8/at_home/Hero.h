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
protected:
	char* _name;
	double _strength;
public:
	// CONSTRUCTORS
	Hero();
	Hero(const char* name, double strength);
	~Hero();
	Hero(const Hero& other);
	// MEMBER FUNCTIONS
	bool isEmpty() const;
	virtual double getStrength() const; // changed, added multiply
	char * getName() const;
	// EXTRA FUNCTIONS
	virtual void setEmpty(); // changed, added multiply
	bool valid(const char * name, double strength);
	virtual void set(const char* name, double strength); // changed, added multiply
	void clear();
	// I/O FUNCTIONS
	virtual void display(std::ostream& ostr) const; // changed
	// OPERATOR OVERLOADS
	void operator -= (double strength);
	void operator += (double strength);
};
// HELPER FUNCTIONS
bool operator < (const Hero& hero, const Hero& other);

#endif