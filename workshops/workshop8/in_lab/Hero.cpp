// OOP244 Workshop 8:  Derived Classes
// File:               Hero.cpp
// Version:            1.0
// Date:               Nov 8, 2016     
/////////////////////////////////////////////

#include <cstring>
#include "Hero.h" // has iostream

using namespace std;

/*********************************** CONSTRUCTORS ************************************/
Hero::Hero()
{
	//clog << "[INFO][HERO CONSTRUCTOR]  Hero::Hero()" << endl;
	setEmpty();
}

Hero::Hero(const char * name, double strength)
{
	//clog << "[INFO][HERO CONSTRUCTOR]  Hero::Hero(const char * name, double strength)" << endl;
	setEmpty();
	if (strlen(name) <= 20)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
		this->_strength = strength;
	}
}

Hero::~Hero()
{
	//clog << "[INFO][HERO DESTRUCTOR]  Hero::~Hero()" << endl;
	clear();
}


/********************************* MEMBER FUNCTIONS **********************************/
// a query that returns true if the object is in a safe empty state, false otherwise
bool Hero::isEmpty() const
{
	//clog << "[INFO][MEMBER FUNCTIONS]  Hero::isEmpty()" << endl;
	return (nullptr == _name);
}

// a query that returns the strength of the hero if the hero object is not empty
// This query returns the value 0.0 if the object is empty
double Hero::getStrength() const
{
	//clog << "[INFO][MEMBER FUNCTIONS]  Hero::getStrength()" << endl;
	if (!isEmpty())
	{
		return _strength;
	}
	else return 0.0;
}

// an extra function that sets the object into a safe empty state
void Hero::setEmpty()
{
	//clog << "[INFO][MEMBER FUNCTIONS]  Hero::setEmpty()" << endl;
	_name = nullptr;
	_strength = 0;
}

// an extra function that deletes dynamic memory 
// and sets the object into a safe empty state
void Hero::clear()
{
	//clog << "[INFO][MEMBER FUNCTIONS]  Hero::clear()" << endl;
	if (!isEmpty())
	{
		delete [] _name;
		setEmpty();
	}
}


/*********************************** I/O FUNCTIONS ***********************************/
// query that receives a reference to an ostream object 
// and inserts into that object “(the name of the hero) - (strength)”
// If the current object is empty, this function does nothing.
void Hero::display(ostream& ostr) const
{
	//clog << "[INFO][I/O FUNCTIONS]  Hero::display(std::ostream& ostr)" << endl;
	if (!isEmpty())
	{
		ostr << _name << " - " << getStrength() << endl;
	}
}


/********************************* OPERATOR OVERLOADS ********************************/
// receives a double and reduces the Hero’s strength by the specified amount
// IF the strength passed in as an argument is greater than the Hero’s strength, 
// then set the Hero’s strength to 0.0.
void Hero::operator -= (double strength)
{
	//clog << "[INFO][OPERATOR OVERLOADS]  Hero::operator -= (double strength)" << endl;
	if (strength < getStrength())
	{ 
		this->_strength -= strength;
	}
	else 
	{ 
		this->_strength = 0;
	}
}

// receives a double and increases the Hero’s strength by the specified amount.
void Hero::operator += (double strength)
{
	//clog << "[INFO][OPERATOR OVERLOADS]  Hero::operator += (double strength)" << endl;
	this->_strength += strength;
}


/********************************** HELPER FUNCTIONS *********************************/
// helper operator that receives references of two objects of type Hero, 
// compares their strengths and returns the result as a bool
bool operator < (const Hero& hero, const Hero& other)
{
	//clog << "[INFO][HELPER FUNCTIONS]  ict::operator < (const Hero& h1, const Hero& h2)" << endl;
	return (hero.getStrength() < other.getStrength());
}