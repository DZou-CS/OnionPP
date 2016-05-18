// piglatin.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string piglatin_op(string s); //output//
string findconsonant(string s);
string findword(string s);


int main()
{
	string user_input;

	//user interaction//
	cout << "enter a sentence to be converted into pig latin: \n";
	getline(cin, user_input);
	cout << endl;
	//output pig latin string//
	cout << piglatin_op(user_input)<<"\n";

	system("PAUSE");
	return 0;
}

//function definitions//
string findconsonant(string s)
{
	string cons_found;
	
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
			cons_found += s[i];

		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			break;		
	}

	return cons_found;
}
string findword(string s)
{
	string firstword;
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] != ' ')
			firstword += s[i];
		else
			break;
	}

	return firstword;
}
string piglatin_op(string s)
{
	string new_sentence;
	string piglatinstring = s;
	
	do {
		string consonant;
		consonant = findconsonant(piglatinstring);
		piglatinstring.erase(0, consonant.size());
		string word;
		word = findword(piglatinstring);
		piglatinstring.erase(0, word.size());
			if (consonant.empty()) 
			{
				new_sentence += word + "-ay ";
			}
		new_sentence += word + "-" + consonant + "ay ";
		}
	while (!piglatinstring.empty());
	
	return new_sentence;
}