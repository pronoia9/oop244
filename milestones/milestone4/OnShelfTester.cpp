// Final Project Milestone 4
// OnShelf Tester program
// File OnShelfTester.cpp
// Version 1.0
// Date 2016/11/16
// Author Fardad Soleimanloo
//
/////////////////////////////////////////////////////////////////
#include "OnShelf.h"
using namespace ict;
using namespace std;
#define FileName "filetest.txt"
void piv(const char* upc, const char* name, const char* price = "", const char* taxed = "", const char* qty = "", const char* qtyNd = "", const char* date = "") {
	cout
		<< "Enter the following: " << endl
		<< "Sku: " << upc << endl
		<< "Name: " << name << endl;
	if (price[0]) cout << "Price: " << price << endl;
	if (taxed[0]) cout << "Taxed: " << taxed << endl;
	if (qty[0]) cout << "Quantity on hand: " << qty << endl;
	if (qtyNd[0]) cout << "Quantity needed: " << qtyNd << endl;
	if (date[0]) cout << "Delivery date: " << date << endl;
	cout << endl;
}
void dumpFile(const char* fname) {
	ifstream f(fname);
	char ch;
	while (!f.get(ch).fail()) {
		cout.put(ch);
	}
	f.clear();
	f.close();
}
void _pause() {
	cout << "****press enter to continue...";
	cin.ignore(1000, '\n');
}

int main() {
	clog << endl << "[INFO]  -  [1]" << endl;
	fstream onShfile(FileName, ios::out);
	clog << endl << "[INFO]  -  [2]" << endl;
	OnShelf onSh;
	clog << endl << "[INFO]  -  [3]" << endl;
	bool ok = true;
	clog << endl << "[INFO]  -  [4]" << endl;
	int i;
	clog << endl << "[INFO]  -  [5]" << endl;
	cout << "--OnShelf test:" << endl;/*
	clog << endl << "[INFO]  -  [6]" << endl;
	cout << "----Price validation test:" << endl;
	clog << endl << "[INFO]  -  [7]" << endl;
	piv("abc", "abc", "abc");
	clog << endl << "[INFO]  -  [8]" << endl;
	cin >> onSh;
	clog << endl << "[INFO]  -  [9]" << endl;
	if (cin.fail()) {
		clog << endl << "[INFO]  -  [10]" << endl;
		cin.clear();
		clog << endl << "[INFO]  -  [11]" << endl;
		cin.ignore(2000, '\n');
		clog << endl << "[INFO]  -  [12]" << endl;
		cout << "Passed " << onSh << endl;
	}
	else {
		clog << endl << "[INFO]  -  [13]" << endl;
		ok = false;
		clog << endl << "[INFO]  -  [14]" << endl;
		cout << "Price validation failed" << endl;
	}
	clog << endl << "[INFO]  -  [15]" << endl;
	_pause();
	if (ok) {
		clog << endl << "[INFO]  -  [16]" << endl;
		cout << "----Taxed validation test:" << endl;
		clog << endl << "[INFO]  -  [17]" << endl;
		piv("abc", "abc", "10", "abc");
		clog << endl << "[INFO]  -  [18]" << endl;
		cin >> onSh;
		if (cin.fail()) {
			clog << endl << "[INFO]  -  [19]" << endl;
			cin.clear();
			clog << endl << "[INFO]  -  [20]" << endl;
			cin.ignore(2000, '\n');
			clog << endl << "[INFO]  -  [21]" << endl;
			cout << "Passed " << onSh << endl;
		}
		else {
			clog << endl << "[INFO]  -  [22]" << endl;
			ok = false;
			clog << endl << "[INFO]  -  [23]" << endl;
			cout << "Quantity validaton failed" << endl;
		}
	}
	clog << endl << "[INFO]  -  [24]" << endl;
	_pause();
	if (ok) {
		clog << endl << "[INFO]  -  [25]" << endl;
		cout << "----Quantity validation test:" << endl;
		clog << endl << "[INFO]  -  [26]" << endl;
		piv("abc", "abc", "10", "y", "abc");
		clog << endl << "[INFO]  -  [27]" << endl;
		cin >> onSh;
		if (cin.fail()) {
			clog << endl << "[INFO]  -  [28]" << endl;
			cin.clear();
			clog << endl << "[INFO]  -  [29]" << endl;
			cin.ignore(2000, '\n');
			clog << endl << "[INFO]  -  [30]" << endl;
			cout << "Passed " << onSh << endl;
		}
		else {
			clog << endl << "[INFO]  -  [31]" << endl;
			ok = false;
			clog << endl << "[INFO]  -  [32]" << endl;
			cout << "Quantity validaton failed" << endl;
		}
	}
	clog << endl << "[INFO]  -  [33]" << endl;
	_pause();*/
	if (ok) {
		clog << endl << "[INFO]  -  [34]" << endl;
		cout << "----Quantity Needed validation test:" << endl;
		clog << endl << "[INFO]  -  [35]" << endl;
		piv("abc", "abc", "10", "n", "10", "abc");
		clog << endl << "[INFO]  -  [36]" << endl;
		cin >> onSh;
		if (cin.fail()) {
			clog << endl << "[INFO]  -  [37]" << endl;
			cin.clear();
			clog << endl << "[INFO]  -  [38]" << endl;
			cin.ignore(2000, '\n');
			clog << endl << "[INFO]  -  [39]" << endl;
			cout << "Passed " << onSh << endl;
		}
		else {
			clog << endl << "[INFO]  -  [40]" << endl;
			ok = false;
			clog << endl << "[INFO]  -  [41]" << endl;
			cout << "Quantity Needed validaton failed" << endl;
		}
	}
	clog << endl << "[INFO]  -  [42]" << endl;
	_pause();
	if (ok) {
		clog << endl << "[INFO]  -  [43]" << endl;
		cout << "----Display test, the output of the Program and yours must match:" << endl;
		clog << endl << "[INFO]  -  [44]" << endl;
		piv("1234", "Box", "123.45", "y", "1", "5");
		clog << endl << "[INFO]  -  [45]" << endl;
		cin >> onSh;
		clog << endl << "[INFO]  -  [46]" << endl;
		cin.ignore(1000, '\n');
		clog << endl << "[INFO]  -  [47]" << endl;
		cout << "--Linear------------" << endl;
		clog << endl << "[INFO]  -  [48]" << endl;
		cout << "Program: 1234|Box                 | 139.50| t |   1|   5|" << endl;
		clog << endl << "[INFO]  -  [49]" << endl;
		cout << "  Yours: " << onSh << endl;
		clog << endl << "[INFO]  -  [50]" << endl;
		cout << "--Form Display------" << endl;
		clog << endl << "[INFO]  -  [51]" << endl;
		cout << "--Program: " << endl;
		clog << endl << "[INFO]  -  [522=]" << endl;
		cout << "upc: 1234" << endl;
		clog << endl << "[INFO]  -  [53]" << endl;
		cout << "name: Box" << endl;
		clog << endl << "[INFO]  -  [54]" << endl;
		cout << "price: 123.45" << endl;
		clog << endl << "[INFO]  -  [55]" << endl;
		cout << "Price after tax: 139.50" << endl;
		clog << endl << "[INFO]  -  [56]" << endl;
		cout << "Quantity On Hand: 1" << endl;
		clog << endl << "[INFO]  -  [57]" << endl;
		cout << "Quantity Needed: 5" << endl;
		clog << endl << "[INFO]  -  [58]" << endl;
		cout << "--Yours: " << endl;
		clog << endl << "[INFO]  -  [59]" << endl;
		onSh.display(cout, false) << endl;
	}
	clog << endl << "[INFO]  -  [60]" << endl;
	_pause();
	if (ok) {
		clog << endl << "[INFO]  -  [61]" << endl;
		cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
		clog << endl << "[INFO]  -  [62]" << endl;
		OnShelf tonSh;
		clog << endl << "[INFO]  -  [63]" << endl;
		onSh.taxed(false);
		clog << endl << "[INFO]  -  [64]" << endl;
		onSh.store(onShfile);
		clog << endl << "[INFO]  -  [65]" << endl;
		onSh.store(onShfile);
		clog << endl << "[INFO]  -  [66]" << endl;
		onShfile.close();
		clog << endl << "[INFO]  -  [67]" << endl;
		cout << "--Store OnShelf, program: " << endl
			<< "O,1234,Box,123.45,0,1,5" << endl
			<< "O,1234,Box,123.45,0,1,5" << endl;
		cout << "--Store OnShelf, yours: " << endl;
		clog << endl << "[INFO]  -  [68]" << endl;
		dumpFile(FileName);
		clog << endl << "[INFO]  -  [69]" << endl;
		cout << "--Load OnShelf: " << endl;
		clog << endl << "[INFO]  -  [70]" << endl;
		onShfile.open(FileName, ios::in);
		clog << endl << "[INFO]  -  [71]" << endl;
		onShfile.ignore(2);
		clog << endl << "[INFO]  -  [72]" << endl;
		tonSh.load(onShfile);
		clog << endl << "[INFO]  -  [73]" << endl;
		cout << "Program: 1234|Box                 | 123.45|   |   1|   5|" << endl;
		clog << endl << "[INFO]  -  [74]" << endl;
		cout << "  Yours: " << tonSh << endl;
		clog << endl << "[INFO]  -  [75]" << endl;
		onShfile.clear();
		clog << endl << "[INFO]  -  [76]" << endl;
		onShfile.close();
	}
	return 0;
}