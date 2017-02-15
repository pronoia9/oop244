// OOP244 Workshop 8:  Derived Classes
// File:               SuperHero.h
// Version:            1.0
// Date:               Nov 9, 2016      
/////////////////////////////////////////////

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

class SuperHero : public Hero
{
private:
	double _multiply;
public:
	// CONSTRUCTORS
	SuperHero();
	SuperHero(const char * name, double strength, double multiply);
	~SuperHero();
	SuperHero(const SuperHero&);
	// MEMBER FUNCTIONS
	double getStrength() const;
	// EXTRA FUNCTIONS
	void setEmpty();
	void set(const char* name, double strength, double multiply = 1);
	// I/O FUNCTIONS
	void display(std::ostream& ostr) const;
	// OPERATOR OVERLOADS
	void operator *= (SuperHero& other);
	//SuperHero& operator = (const SuperHero & other);
	//SuperHero& operator = (const Hero & other);
};
#endif