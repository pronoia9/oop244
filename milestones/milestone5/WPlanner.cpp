// OOP244 Milestone 5: Wedding Planner App
// File:               WPlanner.cpp
// Version:            1.0
// Date:               Dec 3, 2016            
// Author:             Jay Ansin            
// Email:              cansin@myseneca.ca           
// Student Number:     123081150     
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;
namespace ict {
	WPlanner::WPlanner(const char* filename)
	{
		//clog << "[INFO]  -  WPlanner(const char* filename)" << endl;
		// copies filename to the filename_ member variable
		strcpy(filename_, filename);  // assuming filename is valid
		// sets all the items_ to nullptr
		for (int i = 0; i < MAX_NO_RECS; i++) { items_[i] = nullptr; }
		// sets _noOfItemsto 0
		noOfItems_ = 0;
		// loads the records, if any, from the file (calls loadRecs function);
		loadRecs();
	}


	void WPlanner::saveRecs()
	{
		clog << "[INFO]  -  WPlanner::saveRecs()" << endl;
		// This function opens the file for writing,
		datafile_.open(filename_, ios::out);
		if (datafile_.is_open())
		{
			// loops through the items_ array up to _noOfItems
			for (int i = 0; i < noOfItems_; i++)
			{
				clog << "[INFO]  -  items_[i]->store(datafile_, true)" << endl;
				// and stores each Good in the datafile
				if (nullptr != items_[i]) { items_[i]->store(datafile_); }
			}
		}
		datafile_.clear();
		// Finally, closes the file
		datafile_.close();
	}


	void WPlanner::loadRecs()
	{
		//clog << "[INFO]  -  WPlanner::loadRecs()" << endl;
		// set readIndex to zero
		int i = 0;
		// open the file for reading (use ios::in)
		datafile_.open(filename_, ios::in);
		// if the file is in fail state it means there is no file on the disk, then
		if (datafile_.fail())
		{
			// clear the failure
			datafile_.clear();
			// close the file
			datafile_.close();
			// open the file for writing (ios::out) to create the file
			datafile_.open(filename_, ios::out);
			// close thefile
			datafile_.close();
		}
		// otherwise, if (!datafile_.fail())
		else
		{
			char id = ' ';
			// until reading fails loop, (!datafile_.fail() && !datafile_.eof())
			while (true)
			{
				// read one character into Id character
				datafile_ >> id;
				if (datafile_.fail())  { break; }
				

				// Delete the memory pointed the item_ pointer at readindex
				delete[] items_[i];
				// if Id character is C,
				if (id == 'C')
				{
					// Dynamically create a CustomMade object and store its address in the items_ pointer at readIndex
					items_[i] = new CustomMade();
				}
				// if Id character is O
				else if (id == 'O')
				{
					// Dynamically create an OnShelf object and store its address in the items_ pointer at readIndex
					items_[i] = new OnShelf();
				}
				// if either C or O is read 
				else { continue; }
				// skip the comma in the file record
				datafile_.ignore();
				// load the Good from the file (using virtual load method)
				items_[i]->load(datafile_);
				// add one to read index
				i++;
				// continue the loop
			}
			// set number of items_ read to readIndex
			noOfItems_ = i;
			// close the datafile
			datafile_.close();
		}
	}


	void WPlanner::getSku(char* sku)
	{
		//clog << "[INFO]  -  WPlanner::getSku(char* sku)" << endl;
		// Prompts the user to enter the SKU
		cout << "Please enter the SKU: ";
		// Then it will receive the Sku from user into the “sku” argument up to MAX_SKU_LEN + 1 or up to ‘\n’ using itstream::getline()
		cin >> sku;  //cin.get(sku, MAX_SKU_LEN + 1, '\n');  
		cout << endl;
		// If istream fails,
		if (cin.fail())
		{
			// it will clear the istream
			cin.clear();
			// and flush the the keyboard of any remaining characters
			//.flush(); 
			cin.ignore(2000, '\n');
		}
	}


	void WPlanner::deleteItem()
	{
		//clog << "[INFO]  -  WPlanner::deleteItem()" << endl;
		char item[MAX_SKU_LEN + 2];
		item[0] = '\0';
		// Get the Sku of the function use getSku() function 
		getSku(item);
		// and search the items_ array for the Good
		int i = SearchItems(item);
		// If not found print "Item Not found!" and skip two lines
		if (i == -1) { cout << "Item Not found!" << endl << endl; }
		// If found, if (i != -1)
		else 
		{
			char c = ' ';
			// print: "The following Item will be deleted:"<NewLine>
			cout << "The following Item will be deleted: " << endl;
			// and display the the Good in no linear format
			items_[i]->display(cout, false);
			// Then skip two lines and ask for confirmation with this message:
			cout << endl << endl << "Type (Y) to confirm or (N) to abort: ";
			cin >> c;
			// If user enters ‘Y’ or ‘y’,
			if (c == 'Y' || c == 'y')
			{
				// skip a line,
				cout << endl;
				// delete the item in array,
				delete [] items_[i];
				// if the item deleted is the last on the array, then no need for shifting
				if (nullptr != items_[i + 1])  
				{
					//clog << "[INFO]  -  [1] WPlanner::deleteItem()" << endl;
					// shift the values of the rest of the array once towards the deleted item,
					for (int n = i; n < noOfItems_ - 1; n++)
					{
						//clog << "[INFO]  -  [2] WPlanner::deleteItem()" << endl;
						if (nullptr != items_[n + 1])  { items_[n] = items_[n + 1]; };
					}
					//clog << "[INFO]  -  [3] WPlanner::deleteItem()" << endl;
					if (nullptr != items_[noOfItems_ - 1])  { delete [] items_[noOfItems_ - 1]; }
				}
				// reduce noOfItems_ by one
				noOfItems_--;
				clog << "[INFO]  -  [4] WPlanner::deleteItem()" << endl;
				// and save the items_ into the file
				saveRecs();
				// Finally print "Item deleted!" and skip two lines
				cout << "Item deleted!" << endl << endl;
			}
			// If user enters anything but ‘Y’ or ‘y’, print "Aborted!" and skip two lines
			else { cout << endl << "Aborted!" << endl; }
		}
		item[0] = '\0';
	}


	void WPlanner::updateQty()
	{
		//clog << "[INFO]  -  WPlanner::updateQty()" << endl;
		char item[MAX_SKU_LEN + 2];
		item[0] = '\0';
		// This function will get the Sku of the Good to be updated using getSku() method
		getSku(item);
		int i = SearchItems(item);
		// and then if the Good is found in the items_ array / if it finds a match
		if (i != -1)
		{
			int amount = 0;
			// it displays the Good in non-linear format
			items_[i]->display(cout, false);
			// skips a line, and asks the user for the quantity purchased in the form of an int
			cout << endl << endl << "Please enter the number of purchased goods: ";
			//cin.clear();
			cin >> amount;
			// If this function cannot read the integer it prints:
			if (cin.fail()) { cout << "Invalid Quantity value!" << endl; }
			// If this function reads the integer
			else
			{
				// it makes sure the amount specified is less than or equal to the amount required (< qtyNeeded() - quantity())
				int required = (items_[i]->qtyNeeded() - items_[i]->quantity());
				// If the amount specified is less than or equal to the amount required
				if (amount <= required)
				{
					// this function adds the value to the quantity on hand using int Good::operator+=(int quantity)
					//items_[i] += amount;
					items_[i]->quantity(items_[i]->quantity() + amount);
				}
				// If the amount specified is not less than or equal the amount required
				else 
				{
					// this function only accepts the amount required
					//items_[i] += required;
					items_[i]->quantity(items_[i]->quantity() + required);
					// and prints a message to return the extra
					cout << endl << "Too many purchased, only " << required << " needed, please return the extra " 
						 << (amount - required) << "." << endl;
				}
				// After processing the user’s input, this function save all records back to the file 
				saveRecs();
				// and prints:
				cout << endl << "Updated!" << endl;
			}
		}
		// If the Sku is not found, if (i == -1)
		else
		{
			// following error message is displayed:
			cout << endl << "Not found!" << endl;
		}
		item[0] = '\0';
		// Finally, it flushes any extra characters from the keyboard buffer
		cin.clear();
		//.flush();
	}


	void WPlanner::listItems() const
	{
		//clog << "[INFO]  -  WPlanner::listItems()" << endl;
		double total = 0;
		// First, this function prints the following title:
		cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
			<< "-----|-----|--------------------|-------|---|----|----|----------" << endl;
		// Then, this function loops through the items_ array up to _noOfItems and for each Good
		for (int i = 0; i < noOfItems_; i++)
		{
			// prints the Row number in a field of 4 right-justified, a Bar character (|) surrounded by two spaces 
			cout << std::setfill(' ') << right << setw(4) << i+1 << " | ";
			// prints the current Good followed by a newline
			items_[i]->display(cout, true);
			cout << endl;
			// calculates the total cost of the Goods in a double value using operator+=(double & qty, const Good & good)
			total += (items_[i]->quantity(), *items_[i]);  // ???
		}
		// After this function has completed printing the list, it prints:
		cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;
		// and then prints the total cost
		cout << "Total cost of the Wedding: " << "$" << setprecision(2) << total << endl;
	}


	int WPlanner::SearchItems(const char* sku)const
	{
		//clog << "[INFO]  -  WPlanner::SearchItems(const char* sku)const" << endl;
		// This function loops through the items_ array up to _noOfItems
		for (int i = 0; i < noOfItems_; i++)
		{
			// and checks each one for the same SKU as the incoming argument using the operator== implemented for the Good class
			if (*items_[i] == sku)   // ?????????
			{ 
				// If it finds a match it returns the index,
				return i; 
			}
		}
		// otherwise it returns -1
		return -1;
	}


	void WPlanner::addItem(bool isCustomMade)
	{
		//clog << "[INFO]  -  WPlanner::addItem(bool isCustomMade)" << endl;
		Good * item;
		// Depending on the value of isCustomMade, this function creates a CustomMade,
		if (isCustomMade)
		{
			item = new CustomMade();
		}
		// or OnShelf object, if (!isCustomMade)
		else
		{
			item = new OnShelf();
		}
		// and gets its values from the user
		item->conInput(cin);
		// If an error occurs,
		if (cin.fail())
		{
			// it displays the Good 
			item->display(cout, false);
			// and exits the function
			//return;
		}
		// If no error occurs,
		else
		{
			// it adds the new Good to the end of the items_ array adding one to the no of items(noOfItems_)
			items_[noOfItems_] = item;
			noOfItems_++;
			// and saves the items_ into the datafile_ using saveRecs()
			saveRecs();
			cout << endl << "Good added" << endl;
		}
	}


	int WPlanner::menu()
	{
		//clog << "[INFO]  -  WPlanner::menu()" << endl;
		int selection = -1;
		// Displays the menu as follows,
		cout << "Wedding Planner Management Program" << endl
			<< "1 - List goods" << endl
			<< "2 - Add On Shelf Good" << endl
			<< "3 - Add Custom-Made Good" << endl
			<< "4 - Update Good quantity" << endl
			<< "5 - Delete" << endl
			<< "0 - Exit program" << endl
			<< "> ";
		// and waits for the user to select an option
		//cin.sync();
		cin.clear();
		cin >> selection;
		cout << endl;
		// If the user’s selection is valid, this function returns the selection
		// If the user’s selection is invalid,
		if (!(selection >= 0 && selection <= 5) || cin.fail())
		{
			// this function returns -1
			selection = -1;
			// Erases any characters in the keyboard buffer before returning control to its caller
			cin.clear();
			cin.ignore(2000, '\n');
		}
		// clear here?
		return selection;
	}


	int WPlanner::run()
	{
		//clog << "[INFO]  -  WPlanner::run()" << endl;
		bool done = false;
		while (!done)
		{
			// This function displays the menu, and depending on the user’s selection performs the requested action
			switch (menu())
			{
			// 1 - List goods
			case 1:
				//clog << endl << "[INFO]  -  [1]" << endl;
				listItems();
				cout << endl;
				break;
			// 2 - Add On Shelf Good
			case 2:
				//clog << endl << "[INFO]  -  [2]" << endl;
				addItem(false);
				cout << endl;
				break;
			// 3 - Add Custom-Made Good
			case 3:
				//clog << endl << "[INFO]  -  [3]" << endl;
				addItem(true);
				cout << endl;
				break;
			// 4 - Update Good quantity
			case 4:
				//clog << endl << "[INFO]  -  [4]" << endl;
				updateQty();
				cout << endl;
				break;
			// 5 - Delete
			case 5:
				//clog << endl << "[INFO]  -  [5]" << endl;
				deleteItem();
				cout << endl;
				break;
			// 0 - Exit program, if the user selects 0,
			case 0:
				//clog << endl << "[INFO]  -  [0]" << endl;
				// it stops displaying the menu once the user has entered zero to exit
				done = true;
				// displaying the following message:
				cout << "Goodbye!!" << endl << endl;
				// and exits the function
				break;
			// If the user selects an invalid option,
			case -1:
				// it function prints:
				cout << "===Invalid Selection, try again.===" << endl << endl;
				break;
			}
			cin.clear();
			cin.ignore(2000, '\n');
		}
		return 0;
	}
}