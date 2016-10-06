// Fractions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fractions.h"
using namespace std;
bool symbol_check(char c);
bool denominator_check(int d);
int main()
{
	int n; int d; char div_symbol;
	cout << "enter a fraction" << endl;
	cin >> n >> div_symbol >> d;
	
	/// integrity check
	if (cin.fail()) {
		cout << "failed" << endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}
	if (symbol_check(div_symbol) == false) { 
		cerr << "error" << endl;
		system("PAUSE");
		return EXIT_FAILURE;
		
	}
	if (denominator_check(d) == false) {
		cerr << "error /0 " << endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	
	//////////////////////
	_fractions_ f1(n, d);
	_fractions_ f2(3, 4);


	system("PAUSE");
	return EXIT_SUCCESS;
}

bool symbol_check(char c) {
	if ((c == ' ') || (c == '/')) {
		return true;
	}
		return false;
}
bool denominator_check(int d) {
	if ((d == 0) || (d <= 0)) {
		return false;
	}
	return true;
}