// OOP244 Workshop 8: Derived Classes
// File	w8_at_home.cpp
// Version 1.0
// Date	2016/11/06
// Author	Franz Newland, Eden Burton
// Description
//      This file demonstrates the client module of w8
/////////////////////////////////////////////////////

#include <iostream>
#include "SuperHero.h"

int main()
{
	SuperHero p;
	std::clog << std::endl;
	p.display(std::cout);
	std::clog << std::endl;

	SuperHero w("wimpy", -10, 5);
	std::clog << std::endl;
	w.display(std::cout);
	std::clog << std::endl;

	SuperHero h("Hercules", 100, 5);
	std::clog << std::endl;
	h.display(std::cout);
	std::clog << std::endl;

	SuperHero hClone(h);
	std::clog << std::endl;
	hClone.display(std::cout);
	std::clog << std::endl;

	SuperHero sm("Superman", 130, 5);
	std::clog << std::endl;
	sm.display(std::cout);
	std::clog << std::endl;

	std::cout << "Superman battles Hercules' clone!" << std::endl;
	std::clog << std::endl;
	sm *= hClone;
	std::clog << std::endl;

	sm.display(std::cout);
	std::clog << std::endl;
	hClone.display(std::cout);
	std::clog << std::endl;

	std::cout << "Hercules battles Superman!" << std::endl;
	std::clog << std::endl;
	h *= sm;
	std::clog << std::endl;

	sm.display(std::cout);
	std::clog << std::endl;
	hClone.display(std::cout);
	std::clog << std::endl;

	// Reflection section
	Hero o = sm;  // Why does this compile?
	std::clog << std::endl;
	o.isEmpty();
	std::clog << std::endl;
	
	// Uncomment the following two lines to see what happens. Explain the result!
	//Hero o2;
	//std::clog << std::endl;
	//SuperHero sh = o2;
	//std::clog << std::endl;

	return 0;
}