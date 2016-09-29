// Add digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//int Count_Digits(int x);

int main()
{
	int input; int sum = 0;
	vector <int> vec;

	cout << "enter a number \n";
	cin >> input;

	//integrity check
	if (cin.fail()) {
		cerr << "not an integer \n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	if ((input <= 0) && (input >= 1000000000)) {
		cerr << "invalid input \n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	//
	while (input > 0) {
		sum += input % 10;
		input /= 10;
	}
	cout << "sum of digits: " << sum << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*
int Count_Digits(int x){
	x = abs(x);
	return (x < 10 ? 1 :
		(x < 100 ? 2 :
		(x < 1000 ? 3 :
			(x < 10000 ? 4 :
			(x < 100000 ? 5 :
				(x < 1000000 ? 6 :
				(x < 10000000 ? 7 :
					(x < 100000000 ? 8 :
					(x < 1000000000 ? 9 :
						10)))))))));
	return x;
}
*/
