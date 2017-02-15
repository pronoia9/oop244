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
	//clog << "[INFO][CONSTRUCTOR]  Hero::Hero()" << endl;
	setEmpty();
}

Hero::Hero(const char * name, double strength)
{
	//clog << "[INFO][CONSTRUCTOR]  Hero::Hero(const char * name, double strength)" << endl;
	set(name, strength);
}

Hero::~Hero()
{
	//clog << "[INFO][DESTRUCTOR]  Hero::~Hero()" << endl;
	clear();
}

Hero::Hero(const Hero & other)
{
	//clog << "[INFO][COPY CONSTRUCTOR]  Hero::Hero(const Hero & other)" << endl;
	if (!isEmpty())
	{
		clear();
	}
	set(other._name, other._strength);
}


/********************************* MEMBER FUNCTIONS **********************************/
bool Hero::isEmpty() const
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::isEmpty()" << endl;
	return (_strength < 0);  // || nullptr == _name
}

double Hero::getStrength() const
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::getStrength()" << endl;
	if (!isEmpty())
	{
		return _strength;
	}
	else return 0;
}

char * Hero::getName() const
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::getName() const" << endl;
	return _name;
}


/********************************** EXTRA FUNCTIONS **********************************/
void Hero::setEmpty()
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::setEmpty()" << endl;
	_name = nullptr;
	_strength = -1;
}

bool Hero::valid(const char * name, double strength)
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::valid()" << endl;
	return (strlen(name) <= 20 && strength >= 0);
}

void Hero::set(const char * name, double strength)
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::set(const char * name, double strength)" << endl;
	if (valid(name, strength))
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
		_strength = strength;
	}
	else
	{
		setEmpty();
	}
}

void Hero::clear()
{
	//clog << "[INFO][MEMBER FUNCTION]  Hero::clear()" << endl;
	if (!isEmpty() && nullptr != _name)
	{
		delete[] _name;
		this->setEmpty();  // class's own setEmpty()?
	}
}


/*********************************** I/O FUNCTIONS ***********************************/
void Hero::display(ostream & ostr) const
{
	//clog << "[INFO][I/O FUNCTION]  Hero::display(std::ostream& ostr)" << endl;
	if (!isEmpty())
	{
		ostr << _name << " - " << getStrength() << endl;
	}
}


/********************************* OPERATOR OVERLOADS ********************************/
void Hero::operator -= (double strength)
{
	//clog << "[INFO][OPERATOR OVERLOAD]  Hero::operator -= (double strength)" << endl;
	if (strength < this->_strength)
	{
		this->_strength -= strength;
	}
	else
	{
		this->_strength = 0;
	}
}

void Hero::operator += (double strength)
{
	//clog << "[INFO][OPERATOR OVERLOAD]  Hero::operator += (double strength)" << endl;
	this->_strength += strength;
}


/********************************** HELPER FUNCTIONS *********************************/
bool operator < (const Hero & hero, const Hero & other)
{
	//clog << "[INFO][HELPER FUNCTION]  ict::operator < (const Hero& h1, const Hero& h2)" << endl;
	return (hero.getStrength() < other.getStrength());
}