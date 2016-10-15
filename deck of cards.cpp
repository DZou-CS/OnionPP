// deck of cards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class deck {
private:
	enum suits { diamonds, clovers, hearts, spades };
	enum card_number {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
public:
	string deck::cards[13][4];
	void auto_populate_deck() {
		int n = 0;
		for (int s = 0; s < 4; s++) {
			for (int n = 0; n < 13; n++) {
				cards[n][s] = card_number(n), suits(s);
			}
		}
	}
	//
	void print_deck() {
		for (int n = 0; n < 13; n++) {
			for (int s = 0; s < 4; s++) {
				cout << cards[n][s];
			}
			cout << endl;
		}
	}
};

int main()
{
	deck x;
	x.auto_populate_deck();
	x.print_deck();

	system("PAUSE");
    return 0;
}

