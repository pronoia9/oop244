// OOP244 Workshop 1: Compiling modular source code
// File	seneGraph.cpp
// Version 1.0
// Date             2016/09/20
// Author           Ceyda Ansin, 123081150
// Description      Workshop 1
// This provides some source code in a single file to break
// into modules and compile together
/////////////////////////////////////////////////////////////////


#include <iostream>
#include "graph.h"
#include "tools.h"
using namespace std;

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

// SeneGraph program
int main() {
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;
	cout << "Welcome to SeneGraph" << endl;
	while (!done) {
		cout << "No Of Samples: " << noOfSamples << endl;
		switch (menu()) {
		case 1:
			cout << "Enter number of samples on hand: ";
			noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else {
				cout << "Please enter the sample values: " << endl;
				getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else if (samples[0] == 0) {
				cout << "Firt enter the samples." << endl;
			}
			else {
				printGraph(samples, noOfSamples);
			}
			break;
		case 0:
			cout << "Thanks for using SeneGraph" << endl;
			done = true;
		}
	}
	return 0;
}