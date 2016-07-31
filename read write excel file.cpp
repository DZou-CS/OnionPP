// read write excel file.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*notes:
	all files must be in .csv file format, .csv seperates cells with comas(,) which allows for easy access to data in each cell
	eof = end of file

*/

int main()
{
// file delcarations
	ifstream fs_chola;         //file stream chola
	ifstream fs_master_menu;   //file stream master_menu
	ifstream indata;
	ofstream outdata;
// variable declarations
	string LineA;
	int x;
	int col = 0;
	int row = 0;
	int arrayA[10][10] = { {0} };
// open file
	fs_chola.open("CHOLAWCODE.xlsx");
	if (fs_chola.is_open())
	{
		cout << "chola file successfully opened\n";
	}
	if (fs_chola.fail())
	{
		cerr << "file(chola) not found!"<< endl;
	}

	fs_master_menu.open("master_menu.csv");
	if (fs_master_menu.is_open())
	{
		cout << "master menu file successfully opened\n";
	}
	if (fs_master_menu.fail())
	{
		cerr << "file(master menu) not found! " << endl;
	}
// read file
	while (fs_master_menu.good()){

		while (getline(fs_master_menu, LineA)){
			istringstream streamA(LineA);

			while (streamA >>x){
				arrayA[row][col] = x;
				col++;
			}
			row++;
		}
	}
	cout << "done \n";
// show colums and rows (checking for correct answers)
	cout << "number of rows: " << row << endl;
	cout << "number of columns: " << col << endl;
	system("PAUSE");
    return 0;
}

