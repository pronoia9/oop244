// OOP244 Milestone 4: Onshelf and Custommade Classes
// File:               OnShelf.h
// Version:            1.2
// Date:               Dec 3, 2016            
// Author:             Jay Ansin            
// Email:              cansin@myseneca.ca           
// Student Number:     123081150     
/////////////////////////////////////////////

#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__

#include "Good.h"
#include "Error.h"

namespace ict
{
	class OnShelf : public Good
	{
	private:
		char recTag_;  // Holds a single character to tag the records as CustomMade (‘C’) or OnShelf (‘O’) Good in a file

	protected:
		Error err_;

	public:
		OnShelf();  // x
		OnShelf(char code);
		std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& display(std::ostream& ostr, bool linear) const;
		std::istream& conInput(std::istream& istr);
	};
}

#endif