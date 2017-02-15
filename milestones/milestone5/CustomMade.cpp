// OOP244 Milestone 4: Onshelf and Custommade Classes
// File:               CustomMade.cpp
// Version:            1.0
// Date:               Nov 19, 2016     
/////////////////////////////////////////////

#include "CustomMade.h"

using namespace std;
namespace ict
{
	CustomMade::CustomMade() : OnShelf('C')  // x
	{
		//clog << "[INFO]  -  CustomMade::CustomMade() : OnShelf('C')" << endl;
	}

	const Date & CustomMade::delivery() const
	{
		//clog << "[INFO]  -  CustomMade::delivery()" << endl;
		return delivery_;
	}

	void CustomMade::delivery(const Date & value)
	{
		//clog << "[INFO]  -  CustomMade::delivery(const Date & value)" << endl;
		delivery_ = value; // basic/default copy con is fine
	}

	std::fstream & CustomMade::store(std::fstream & file, bool addNewLine) const
	{
		//clog << "[INFO]  -  CustomMade::store(std::fstream & file, bool addNewLine)" << endl;
		OnShelf::store(file, false);
		file << "," << delivery();
		if (addNewLine) file << endl;
		return file;
	}

	std::fstream & CustomMade::load(std::fstream & file)
	{
		//clog << "[INFO]  -  CustomMade::load(std::fstream & file)" << endl;
		Date temp;
		OnShelf::load(file);
		//delivery_.read(file);
		file >> temp;
		file.ignore();
		delivery(temp);
		return file;
	}

	std::ostream & CustomMade::display(std::ostream & ostr, bool linear) const
	{
		//clog << "[INFO]  -  CustomMade::display(std::ostream & ostr, bool linear)" << endl;
		OnShelf::display(ostr, linear);
		if (err_.isClear() && NULL != this)
		{
			if (linear)
			{
				ostr << delivery();
			}
			else
			{
				ostr << endl << "delivery date: " << delivery();
			}
		}
		return ostr;
	}

	std::istream & CustomMade::conInput(std::istream & istr)
	{
		//clog << "[INFO]  -  CustomMade::conInput(std::istream & istr)" << endl;
		OnShelf::conInput(istr);
		if (err_.isClear())
		{
			Date temp;
			cout << "delivery date (YYYY/MM/DD) : ";
			temp.read(istr);

			if (temp.bad())
			{
				     if (CIN_FAILED == temp.errCode())  err_.message("Invalid Date Entry");
				else if (YEAR_ERROR == temp.errCode())  err_.message("Invalid Year in Date Entry");
				else if (MON_ERROR  == temp.errCode())  err_.message("Invalid Month in Date Entry");
				else if (DAY_ERROR  == temp.errCode())  err_.message("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
			}
			else
			{
				delivery_ = temp;
			}
		}
		return istr;
	}
}