// find empty cell.cpp : Defines the entry point for the console application.
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

	ifstream in("test_copy.csv"); // in paranthesis, input the name
	ofstream out("output_file.csv", ios::app);

	if (in.is_open()) {
		cout << "file is open \n";
	}
	else
		cerr << "file not fount \n";

	//declarations       //constructor

	string line, field;
	vector< vector<string> > array;  // the 2D array
	vector<string> v;                // array of values for one line only



									 //read into array
	cout << "reading file... \n";
	while (getline(in, line)) {
		v.clear();
		stringstream ss(line);
		// break line into comma delimitted fields
		while (getline(ss, field, ',')) {
			v.push_back(field);
		}

		array.push_back(v);  // add the 1D array to the 2D array
	}

	//file delcarations
	size_t row;
	int row_number = 0;

	cout << "working... \n";
	for (size_t i = 0; i<array.size(); ++i) {
		string retrieved_sku;
		for (size_t j = 0; j<array[i].size(); ++j) {
			//cout << array[i][j] << "|";
			//where the search for empty cell and retrieval happens
			if((array[i][1].empty()) || (array[i][1] ==" ") || (array[i][1] == "  "))
			{
				out << array[i][j];
				out << ',';
				row_number = i;
			}
			//copy all rows and append to output file
		}
		out << endl;          //append to next row on output file
		cout << "\n";		  //read/start on next row on input file
		cout << row_number << " is empty" << endl;
	}

	in.close();
	out.close();
	cout << "done" << endl;

	system("PAUSE");
	return 0;
}
