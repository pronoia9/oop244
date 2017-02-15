#ifndef ICT_WPlanner_H__
#define ICT_WPlanner_H__

#include "Good.h"

namespace ict
{
	class WPlanner
	{
	private:
		char filename_[256];        // holds the name of the text file that stores the Goods' information
		Good* items_[MAX_NO_RECS];  // an array of pointers to Good objects
		std::fstream datafile_;     // an instance of an fstream class that refers to a file
		int noOfItems_;             // holds the number of Goods pointed to by the items_ array

		int menu();
		void loadRecs();
		void saveRecs();
		void listItems()const;
		int SearchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isCustomMade);
		void deleteItem();
		void getSku(char* sku);

	public:
		WPlanner(const char* filename);
		int run();
		//Copy and assignment prevention goes here:
		WPlanner(const WPlanner& WP) = delete;
		WPlanner& operator=(const WPlanner& WP) = delete;
	};
}

#endif