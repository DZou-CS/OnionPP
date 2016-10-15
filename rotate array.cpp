// rotate array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int f = 5;
void leftRotate(int arr[], int displacement, int a_size);
void leftRotatebyOne(int arr[], int a_size);
int main()
{
	int d;
	int arr[f] = {1,2,3,4,5};
	for (int i = 0; i < size(arr); i++) {
		cout << arr[i] << ",";
	}
	////
	cout << endl;
	cout << "how many places would you like to rotate the array? \n";
	cin >> d;
	
	if (cin.fail()) {
		cerr << "stop!!" << endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	///
	leftRotate(arr, d, f);
	cout << endl;
	//cout array
	for (int i = 0; i < size(arr); i++) {
		cout << arr[i] << ",";
	}

	system("PAUSE");
    return 0;
}

void leftRotate(int arr[], int displacement, int a_size){
	for (int i = 0; i < displacement; i++)
		leftRotatebyOne(arr, a_size);
}

void leftRotatebyOne(int arr[], int a_size) {
	int i, temp;
	temp = arr[0];
	for (i = 0; i < a_size - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}