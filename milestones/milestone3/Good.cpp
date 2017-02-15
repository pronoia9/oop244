// OOP244 Milestone 3: Good
// File:               Good.cpp
// Version:            1.0
// Date:               Nov 10, 2016        
/////////////////////////////////////////////

#include <cstring>
#include <iostream>
//#include <string>
#include "wpgeneral.h"
#include "Good.h"

using namespace std;
namespace ict
{
	/******************************************** CONSTRUCTORS *******************************************/
	Good::Good()
	{
		//clog << "[INFO]  Good::Good()" << endl;
		setEmpty();
	}

	Good::Good(const char * sku, const char * name, double price, int qtyNeeded, bool taxed)
	{
		//clog << "[INFO]  Good::Good(const char * sku, const char * name, double price, int qtyNeeded, bool taxed)" << endl;
		set(sku, name, price, taxed, 0, qtyNeeded);
	}

	Good::Good(const Good & source)
	{
		//clog << "[INFO]  Good::Good(const Good & other)" << endl;
		if (nullptr != source._name)  // check source validity
		{
			set(source._sku, source._name, source._price, source._taxed, source._quantity, source._qtyNeeded);
		}
	}

	Good::~Good()
	{
		//clog << "[INFO]  Good::~Good()" << endl;
		if (nullptr != _name)
		{
			delete[] _name;
			setEmpty();
		}
	}
	
	
	/********************************************** SETTERS **********************************************/
	void Good::sku(const char * sku)
	{
		//clog << "[INFO]  Good::setSku(char * sku)" << endl;
		//strcpy_s(_sku, MAX_SKU_LEN, sku);
		strcpy(_sku, sku);
	}

	void Good::name(const char * name)
	{
		//clog << "[INFO]  Good::setName(char * name)" << endl;
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}

	void Good::price(double price)
	{
		//clog << "[INFO]  Good::setPrice(double price)" << endl;
		_price = price;
	}

	void Good::taxed(bool taxed)
	{
		//clog << "[INFO]  Good::setTaxed(bool taxed)" << endl;
		_taxed = taxed;
	}

	void Good::quantity(int quantity)
	{
		//clog << "[INFO]  Good::setQuantity(int quantity)" << endl;
		_quantity = quantity;
	}

	void Good::qtyNeeded(int qtyNeeded)
	{
		//clog << "[INFO]  Good::setQtyNeeded(int qtyNeeded)" << endl;
		_qtyNeeded = qtyNeeded;
	}

	void Good::set(const char * sku, const char * name, double price, bool taxed, int quantity, int qtyNeeded)
	{
		//clog << "[INFO]  Good::set(const char * sku, const char * name, double price, bool taxed, int quantity, int qtyNeeded)" << endl;
		//strcpy_s(_sku, MAX_SKU_LEN, sku);
		strcpy(_sku, sku);
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
		_price = price;
		_taxed = taxed;
		_quantity = quantity;
		_qtyNeeded = qtyNeeded;
	}

	void Good::setEmpty()
	{
		//clog << "[INFO]  Good::setEmpty()" << endl;
		_sku[0] = '\0';
		_name = nullptr;
		_price = 0;
		_taxed = 1;
		_quantity = 0;
		_qtyNeeded = 0;
	}


	/********************************************** GETTERS **********************************************/
	const char * Good::sku() const
	{
		//clog << "[INFO]  char * Good::getSku()" << endl;
		return _sku;
	}

	const char * Good::name() const
	{
		//clog << "[INFO]  char * Good::getName()" << endl;
		return _name;
	}

	double Good::price() const
	{
		//clog << "[INFO]  Good::getPrice()" << endl;
		return _price;
	}

	bool Good::taxed() const
	{
		//clog << "[INFO]  Good::getTaxed()" << endl;
		return _taxed;
	}

	int Good::quantity() const
	{
		//clog << "[INFO]  Good::getQuantity()" << endl;
		return _quantity;
	}

	int Good::qtyNeeded() const
	{
		//clog << "[INFO]  Good::getQtyNeeded()" << endl;
		return _qtyNeeded;
	}

	double Good::cost() const
	{
		//clog << "[INFO]  Good::cost()" << endl;
		double cost = _price;
		if (taxed())
		{
			cost += price() * TAX;
		}
		return cost;
	}


	/********************************************* OPERATORS *********************************************/
	Good & Good::operator=(const Good & source)
	{
		//clog << "[INFO]  Good::operator=(const Good & source)" << endl;
		if (this != &source  &&  nullptr != source._name)  // if this is not the copy source, and check source's validity, then set(...)
		{
			if (nullptr != this->_name) // if this->name is not nullptr, delete name
			{
				delete[] _name;
			}
			set(source._sku, source._name, source._price, source._taxed, source._quantity, source._qtyNeeded);
		}
		return *this;
	}

	bool Good::operator==(const char * skuO) const
	{
		//clog << "[INFO]  Good::operator==(const char * sku)" << endl;
		return (!strcmp(this->_sku, skuO));  // compare SKUs, and return result
	}

	int Good::operator+=(int quantity)
	{
		//clog << "[INFO]  Good::operator+=(int quantity)" << endl;
		return _quantity += quantity;  // increase quantity, and return it
	}


	/********************************************** HELPERS **********************************************/
	double operator+=(double & qty, const Good & good)
	{
		//clog << "[INFO]  operator+=(double & left, const Good & right)" << endl;
		return (qty += good.cost() * good.quantity());
	}

	std::ostream & operator<<(std::ostream & os, Good & good)
	{
		//clog << "[INFO]  operator<<(std::ostream & ostr, Good & good)" << endl;
		return good.display(os, true);
	}

	std::istream & operator>>(std::istream & is, Good & good)
	{
		//clog << "[INFO]  operator >> (std::istream & istr, Good & good)" << endl;
		return good.conInput(is);
	}
}