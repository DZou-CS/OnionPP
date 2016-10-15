// struct access.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct cable {
	string	name;
	string	material;
	int		cable_length;	//ft
	int		cable_diameter; //cm
} ethernet, opticfiber, coax_cable;


int main()
{
	//ethernet def
	ethernet.name = "cat5_ethernet_twisted"; ethernet.material = "copper"; ethernet.cable_diameter = 1; ethernet.cable_length = 6;
	//optic def
	opticfiber.name = "SC_fiber_blue"; opticfiber.material = "polyimide"; opticfiber.cable_diameter = 3; opticfiber.cable_length = 20;
	//coax def
	coax_cable.name = "RG6_CXC"; coax_cable.material = "copper"; coax_cable.cable_diameter = 1; coax_cable.cable_length = 10;

	/*--------------------------------------------------------------------------------------------------------------------------------*/
	//test print
	cout << ethernet.name;

	system("PAUSE");
    return 0;
}

