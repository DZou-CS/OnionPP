// read write excel file.cpp : Defines the entry point for the console application.
// RW master menu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{

	ifstream in("master_menu.csv");
	if (in.is_open()) {
		cout << "file is open \n";
	}
	else
		cerr << "file not fount \n";
	string line, field;

	vector< vector<string> > array;  // the 2D array
	vector<string> v;                // array of values for one line only

	while (getline(in, line))    // get next line in file
	{
		v.clear();
		stringstream ss(line);

		while (getline(ss, field, ','))  // break line into comma delimitted fields
		{
			v.push_back(field); 
		}

		array.push_back(v);  // add the 1D array to the 2D array
	}

	// print out what was read in

	for (size_t i = 0; i<array.size(); ++i)
	{
		for (size_t j = 0; j<array[i].size(); ++j)
		{
			cout << array[i][j] << "|";
		}
		cout << "\n";
	}

	return 0;
}
