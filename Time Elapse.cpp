// Time Elapse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

//////////////////////////////////////////////
int hours = 0;
int minutes = 0;
int seconds = 0;
int miliseconds = 0;
/////////////////////////////////////////////

void start_ticking();

int main()
{
	cout << "press any key to start" << endl;
	char start_timer = _getch();     // waits for key to start
	start_ticking();
	system("PAUSE");
    return 0;
}

void start_ticking()
{
	for (;;)                          //infinite loop
	{
		miliseconds++;
			if (miliseconds == 5199)  //synched with my Seiko "sea urchin" wrist watch
			{
				seconds++;
				miliseconds = 0;
			}
			if (seconds == 59)
			{
				minutes++;
				seconds = 0;
			}
			if (minutes == 59)
			{
			hours++;
			minutes = 0;
		}
			cout << hours << "H :" << minutes << "M :" << seconds << "S" << endl;
	}
}
