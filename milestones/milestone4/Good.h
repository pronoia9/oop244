// OOP244 Milestone 3: Good
// File:               Good.h
// Version:            1.0
// Date:               Nov 10, 2016       
/////////////////////////////////////////////

#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__

#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict
{
	class Good : public ReadWritable
	{
	private:
		char _sku[MAX_SKU_LEN + 1];
		char* _name;
		double _price;
		bool _taxed;
		int _quantity;
		int _qtyNeeded;
	public:
		// Constructors
		Good();
		Good(const char* sku, const char* name, double price, int qtyNeeded, bool taxed = true);
		Good(const Good& source);
		virtual ~Good();

		// Setters
		void sku(const char* sku);
		void name(const char* name);
		void price(double price);
		void taxed(bool taxed);
		void quantity(int quantity);
		void qtyNeeded(int qtyNeeded);
		void set(const char* sku, const char* name, double price, bool taxed, int quantity, int qtyNeeded);  // extra
		void setEmpty();  // extra

		// Getters
		const char* sku() const;
		const char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;

		// Other/Extra Functions
		//bool valid() const;
		//void clear();

		// Operators
		Good& operator=(const Good& source);
		bool operator == (const char * sku)  const;
		int operator += (int quantity);
	};
	// Helpers
	//bool valid(const char* sku, const char* name, double price, bool taxed, int quantity, int qtyNeeded);
	double operator += (double& left, const Good& right);
	std::ostream& operator << (std::ostream& os, Good& good);
	std::istream& operator >> (std::istream& is, Good& good);
}
#endif