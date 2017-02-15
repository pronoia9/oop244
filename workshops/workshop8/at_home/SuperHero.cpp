// OOP244 Workshop 8:  Derived Classes
// File:               SuperHero.h
// Version:            1.0
// Date:               Nov 9, 2016      
/////////////////////////////////////////////

#include <cstring>
#include "SuperHero.h"

using namespace std;

/*********************************** CONSTRUCTORS ************************************/
SuperHero::SuperHero()
{
	//clog << "[INFO][CONSTRUCTOR]  SuperHero::SuperHero()" << endl;
	setEmpty();
}

SuperHero::SuperHero(const char * name, double strength, double multiply)
{
	//clog << "[INFO][CONSTRUCTOR]  SuperHero::SuperHero(char * name, double strength, double multiply)" << endl;
	set(name, strength, multiply);
}

SuperHero::~SuperHero()
{
	//clog << "[INFO][DESTRUCTOR]  SuperHero::~SuperHero()" << endl;
	clear();
}

SuperHero::SuperHero(const SuperHero & other)
{
	//clog << "[INFO][COPY CONSTRUCTOR]  SuperHero(const SuperHero &)" << endl;
	if (!isEmpty())
	{
		clear();
	}
	set(other._name, other._strength, other._multiply);
}


/********************************* MEMBER FUNCTIONS **********************************/
double SuperHero::getStrength() const
{
	//clog << "[INFO][MEMBER FUNCTION]  SuperHero::getStrength()" << endl;
	if (!isEmpty())
	{
		return (_strength * _multiply);
	}
	else return 0;
}


/********************************** EXTRA FUNCTIONS **********************************/
void SuperHero::setEmpty()
{
	//clog << "[INFO][EXTRA FUNCTION]  SuperHero::getStrength()" << endl;
	_name = nullptr;
	_strength = -1;
	_multiply = 0;
}

void SuperHero::set(const char * name, double strength, double multiply)
{
	if (valid(name, strength))
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
		_strength = strength;
		_multiply = multiply;
	}
	else
		setEmpty();
}


/*********************************** I/O FUNCTIONS ***********************************/
void SuperHero::display(std::ostream & ostr) const
{
	//clog << "[INFO][I/O FUNCTION]  SuperHero::display(std::ostream &)" << endl;
	if (!isEmpty())
	{
		ostr << "living superhero! " << _name << " - " << Hero::getStrength() << endl;
	}
	else
	{
		ostr << "deceased superhero!" << endl;
	}
}


/********************************* OPERATOR OVERLOADS ********************************/
void SuperHero::operator*=(SuperHero & other)
{
	//clog << "[INFO][OPERATOR OVERLOAD]  SuperHero::operator*=(SuperHero &)" << endl;
	if (this->getStrength() > other.getStrength())
	{
		this->_strength += other._strength;
		other.setEmpty();
	}
	else if (this->getStrength() < other.getStrength())
	{
		other._strength += this->_strength;
		this->setEmpty();
	}
}