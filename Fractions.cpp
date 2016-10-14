// Fractions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fractions.h"
using namespace std;
bool symbol_check(char c);
int main()
{
	//declarations
	fractions_::_fractions_ f();
	int n; int d; char div_symbol;
	cout << "enter a fraction" << endl;
	cin >> n >> div_symbol >> d;

	if (symbol_check(div_symbol) == false) { 
		cerr << "error! not a fraction" << endl;
		system("PAUSE");
		return EXIT_FAILURE;
		
	}

	//start -- object declaration
	_fractions_ f1(n, d);
	_fractions_ f2(3, 7);   // test
	if (f1.integrity_check() == false) {
		system("PAUSE");
		return EXIT_FAILURE;
	}
	// check values for fraction
	cout << endl;
	cout << f1 << endl;
	cout << f2 << endl;
	
	//simple arithmetic
	_fractions_ sum = f1 + f2;
	cout << sum << endl;
	sum.reduce();

	/* notes */
	// I've tested it with other operations, they work	
	//end
	system("PAUSE");
	return EXIT_SUCCESS;
}

bool symbol_check(char c) {
	if ((c == ' ') || (c == '/')) {
		return true;
	}
		return false;
}
