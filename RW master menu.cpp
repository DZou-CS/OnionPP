// RW master menu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Read_Restaurant.h"
using namespace std;

int main()
{
	//input file and output file
	ifstream in("master_menu.csv");
	ofstream out("test.csv", ios::app);

	if (in.is_open()) {
		cout << "file is open \n";
	}
	else
		cerr << "file not fount \n";

	//declarations
	sku_search operations_;          //constructor

	string line, field;
	vector< vector<string> > array;  // the 2D array
	vector<string> v;                // array of values for one line only



	//read into array
	cout << "reading file... \n"; 
	while (getline(in, line)) {
		v.clear();
		stringstream ss(line);
		// break line into comma delimitted fields
		while (getline(ss, field, ','))  {
			v.push_back(field); 
		}

		array.push_back(v);  // add the 1D array to the 2D array
	}

	//file delcarations
	size_t row;
	string corresponding_master_ID;
	string restaurant_name;


	cout << "working... \n";
	//search for empty SKU cell, retrieve and save the restaurant name and master_ID to use to search restaurant for the SKU and append it to an output file
	for (size_t i = 0; i<array.size(); ++i) {
		string retrieved_sku;
		for (size_t j = 0; j<array[i].size(); ++j) {
			//cout << array[i][j] << "|";
			//where the search for empty cell and retrieval happens
			if ((array[i][1] != "Kokum") && (array[i][14].empty())) {
				corresponding_master_ID = array[i][13];
				restaurant_name = array[i][0];
				retrieved_sku = operations_.read_file(restaurant_name, corresponding_master_ID);
				array[i][14] = retrieved_sku;
				//goto find_restaurant_sku;
			}
			//copy all rows and append to output file
			out << array[i][j];
			out << ',';
		}
		out << endl;          //append to next row on output file
		cout << "\n";		  //read/start on next row on input file
	}

	in.close();
	out.close();

	system("PAUSE");
	return 0;
}

/*
//notes//
all segments inside "find_restaurant_sku is now working
the next thing to do is the write to the cell in the master_menu.csv file
and then save.

what to do:
cut the master_menu.csv in half and then run the program on that
as a proof of concept and a test bench
*/