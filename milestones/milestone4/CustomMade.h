// OOP244 Milestone 4: Onshelf and Custommade Classes
// File:               CustomMade.h
// Version:            1.2
// Date:               Dec 3, 2016       
/////////////////////////////////////////////

#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__

#include "OnShelf.h"
#include "Date.h"
#include "Error.h"

namespace ict
{
	class CustomMade : public OnShelf
	{
	private:
		Date delivery_;

	public:
		CustomMade();
		const Date& delivery()const;
		void delivery(const Date &value);

		std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& display(std::ostream& ostr, bool linear) const;
		std::istream& conInput(std::istream& istr);
	};
}

#endif