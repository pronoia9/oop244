#include <iostream>
#include "String.h"

using namespace std;
using namespace ict;

// prints a string and its properties
ostream& operator~(String& str)
{
	return cout << "->" << str << "<- len: " << str.getLength() << ", mem: " << str.getMemSize() << endl;
}

int main() {
	//clog << endl << "[INFO]  -  [1]" << endl;
	int i;
	//clog << endl << "[INFO]  -  [2]" << endl;
	char str[500] = "One";
	//clog << endl << "[INFO]  -  [3]" << endl;
	String S1;
	//clog << endl << "[INFO]  -  [4]" << endl;
	String S2("Two", 10);
	//clog << endl << "[INFO]  -  [5]" << endl;
	String S3("Three", 4);
	//clog << endl << "[INFO]  -  [6]" << endl;
	String S31(S3);
	//clog << endl << "[INFO]  -  [7]" << endl;
	String tmp;
	//clog << endl << "[INFO]  -  [8]" << endl;
	~S1;
	//clog << endl << "[INFO]  -  [9]" << endl;
	~S2;
	//clog << endl << "[INFO]  -  [10]" << endl;
	~S3;
	//clog << endl << "[INFO]  -  [11]" << endl;
	~S31;
	//clog << endl << "[INFO]  -  [12]" << endl;
	S31 = "Thirty One";
	//clog << endl << "[INFO]  -  [13]" << endl;
	~S31;
	//clog << endl << "[INFO]  -  [14]" << endl;
	cout << (const char*)S31 << endl;
	//clog << endl << "[INFO]  -  [15]" << endl;
	S1 += str;
	//clog << endl << "[INFO]  -  [16]" << endl;
	~S1;
	//clog << endl << "[INFO]  -  [17]" << endl;
	S1 += " ";
	//clog << endl << "[INFO]  -  [18]" << endl;
	~S1;
	//clog << endl << "[INFO]  -  [19]" << endl;
	S1 += S2;
	//clog << endl << "[INFO]  -  [20]" << endl;
	~S1;
	//clog << endl << "[INFO]  -  [21]" << endl;
	tmp = S1++;
	//clog << endl << "[INFO]  -  [22]" << endl;
	~tmp;
	//clog << endl << "[INFO]  -  [23]" << endl;
	tmp = S1 + S3;
	//clog << endl << "[INFO]  -  [24]" << endl;
	~tmp;
	//clog << endl << "[INFO]  -  [25]" << endl;
	++tmp;
	//clog << endl << "[INFO]  -  [26]" << endl;
	~tmp;
	//clog << endl << "[INFO]  -  [27]" << endl;
	cout << '>';
	//clog << endl << "[INFO]  -  [28]" << endl;
	for (i = 0; i < (int)tmp; i++)
	{
		//clog << endl << "[INFO]  -  [29]" << endl;
		cout << tmp[i];
	}
	//clog << endl << "[INFO]  -  [30]" << endl;
	cout << '<' << endl;
	//clog << endl << "[INFO]  -  [31]" << endl;
	tmp[0] = tmp[4] = tmp[8] = 'X';
	//clog << endl << "[INFO]  -  [32]" << endl;
	~tmp;
	return 0;
}
