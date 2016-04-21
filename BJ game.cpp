// BJ game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "bj_game.h"


int main()
{
	srand(time(NULL));
	Game bjgame;
	bjgame.blackjack_game();

	system("PAUSE");
    return 0;
}

