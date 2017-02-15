// OOP244 Milestone 4: Onshelf and Custommade Classes
// File:               OnShelf.cpp
// Version:            1.2
// Date:               Dec 3, 2016        
/////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "OnShelf.h"

using namespace std;
namespace ict 
{
	OnShelf::OnShelf() : Good()
	{
		//clog << "[INFO]  -  OnShelf::OnShelf()" << endl;
		recTag_ = 'O';
	}



	OnShelf::OnShelf(char code) : Good()
	{
		//clog << "[INFO]  -  OnShelf::OnShelf(char code)" << endl;
		recTag_ = code;
	}



	std::fstream & OnShelf::store(std::fstream & file, bool addNewLine) const
	{
		//clog << "[INFO]  -  OnShelf::store(std::fstream & file, bool addNewLine)" << endl;
		file << recTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << qtyNeeded();
		if (addNewLine) file << endl;
		return file;
	}



	std::fstream & OnShelf::load(std::fstream & file)
	{
		//clog << "[INFO]  -  OnShelf::load(std::fstream & file)" << endl;
		//setEmpty();
		char t_sku[MAX_SKU_LEN + 1];
		t_sku[0] = '\0';
		char t_name[21 + 1];
		t_name[0] = '\0';
		double t_price = 0;
		bool t_taxed = 0;
		int t_quantity = 0;
		int t_qtyNeeded = 0;

		file.getline(t_sku, 100, ',');
		file.getline(t_name, 100, ',');
		file >> t_price;
		file.ignore();  // no argument discards single character
		file >> t_taxed;
		file.ignore();
		file >> t_quantity;
		file.ignore();
		file >> t_qtyNeeded;
		file.ignore();

		set(t_sku, t_name, t_price, t_taxed, t_quantity, t_qtyNeeded);

		return file;
	}



	std::ostream & OnShelf::display(std::ostream & ostr, bool linear) const
	{
		//clog << "[INFO]  -  OnShelf::display(std::ostream & ostr, bool linear)" << endl;

		if (!err_.isClear())  { ostr << endl << err_.message() << endl; }
		else if (err_.isClear())
		{
			if (linear)
			{
				ostr << setfill(' ') << left << setw(MAX_SKU_LEN) << sku() << "|"
					 << setw(20) << name() << "|"
					 << right << setw(7) << fixed << setprecision(2) << cost() << "|";

				if (taxed()) ostr << " t |";
				else		 ostr << "   |";

				ostr << setw(4) << quantity() << "|";
				ostr << setw(4) << qtyNeeded() << "|";
			}
			else if (!linear)
			{
				ostr << "Sku: " << sku() << endl;
				ostr << "Name: " << name() << endl;
				ostr << "Price: " << price() << endl;
				if (taxed())        ostr << "Price after tax: " << cost() << endl;
				else if (!taxed())	ostr << "Price after tax: N/A" << endl;
				ostr << "Quantity On Hand: " << quantity() << endl;
				ostr << "Quantity Needed: " << qtyNeeded();
			}
		}
		return ostr;
	}



	std::istream & OnShelf::conInput(std::istream & istr)
	{
		//clog << "[INFO]  -  OnShelf::conInput(std::istream & istr)" << endl;
		char t_sku[MAX_SKU_LEN + 1];
		t_sku[0] = '\0';
		char t_name[21];
		t_name[0] = '\0';
		double t_price = 0;
		char c_tax = 0;
		bool t_taxed = 0;
		int t_quantity = 0;
		int t_qtyNeeded = 0;

		if (!istr.fail())
		{
			//istr.setstate(ios::goodbit);
			err_.clear();
			cout << "Sku: ";
			istr >> t_sku;
			if (istr.fail()) // sku validation
			{
				//err_.message("Invalid SKU Entry");
				istr.setstate(ios::failbit);
			}
			else if (!istr.fail())
			{
				cout << "Name: ";
				istr >> t_name;  // or .getline()
				if (istr.fail()) // name validation
				{
					//err_.message("Invalid Name Entry");
					istr.setstate(ios::failbit);
				}
				else if (!istr.fail())
				{
					cout << "Price: ";
					istr >> t_price;
					if (istr.fail()) // price validation
					{
						err_.message("Invalid Price Entry");
						istr.setstate(ios::failbit);
					}
					else if (!istr.fail())
					{
						cout << "Taxed: ";
						istr >> c_tax;
						if (istr.fail() || (c_tax != 'Y' && c_tax != 'y' && c_tax != 'N' && c_tax != 'n'))
						{
							err_.message("Only (Y)es or (N)o are acceptable");
							istr.setstate(ios::failbit);
						}
						else if (!istr.fail())
						{
							if (c_tax == 'Y' || c_tax == 'y')		t_taxed = true;
							else if (c_tax == 'N' || c_tax == 'n')	t_taxed = false;

							cout << "Quantity On hand: ";
							istr >> t_quantity;
							if (istr.fail()) // qty on hand validation
							{
								err_.message("Invalid Quantity Entry");
								istr.setstate(ios::failbit);
							}
							else if (!istr.fail())
							{
								cout << "Quantity Needed: ";
								istr >> t_qtyNeeded;
								if (istr.fail()) // qty needed validation
								{
									err_.message("Invalid Quantity Needed Entry");
									istr.setstate(ios::failbit);
								}
								else if (!istr.fail())
								{
									set(t_sku, t_name, t_price, t_taxed, t_quantity, t_qtyNeeded);
								}
							}
						}
					}
				}
			}
		}
		//istr.ignore(2000, '\n');
		//istr.clear();
		return istr;
	}
}