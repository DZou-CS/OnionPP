#pragma once
#ifndef BJGAME_H
#define BJGAME_H
#include <iostream>
#include <cmath>
using namespace std;
	class Game
	{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public:
		int players_hand = 0;
		int dealers_hand = 0;
		int d_final_hand = 0.00;
		int p_final_hand = 0;
		int draw_card() { int card = rand() % 13 + 1; return card; }

		void blackjack_game()
		{
			int players_turn = 0;
			int dealers_turn = 0;
			while (players_hand < 21) 
			{
				char init_game;
				cout << "draw a card? y/n \n";
				cin >> init_game;
				if (init_game == 'y') 
				{
					int p_card_drawn = draw_card();
					players_hand += p_card_drawn;
					cout << "you've drawn " << p_card_drawn << ", you are currently holding " << players_hand << endl;
					players_turn++;
				}
				if ((init_game == 'n') && (players_hand != 0))
				{
					p_final_hand = players_hand;
					break;
				}

				while ((dealers_hand < 21) && (players_turn > dealers_turn))
				{
					bool d_decides = ai_behavior();
					if (d_decides == false)
					{
						d_final_hand = dealers_hand;
						cout << "dealer doesnt want to draw anymore cards" << endl;
						break;
					}
					if (d_final_hand > 0.00)
					{
						goto stay;
					}
					else if (d_decides == true)
					{
						int d_card_drawn = draw_card();
						d_card_drawn = card_value(d_card_drawn);
						dealers_hand += d_card_drawn;
						cout << "dealer draws " << d_card_drawn << ", dealer is currently holding " << dealers_hand << endl;
						dealers_turn++;
					}
				}
				if (dealers_hand > 21)
				{
					cout << "dealer busts! you win \n";
					break;
				}
				if (players_hand > 21)
				{
					cout << "bust! you lose \n";
					break;
				}
			}
			if (players_hand = 21)
			{
				cout << "BLACK JACK!!! YOU WIN! \n";
			}
			if (dealers_hand = 21)
			{
				cout << "HOUSE WINS!!! YOU LOSE! \n";
			}
		stay:
			{
				cout << "dealer stays \n";
			}
		}
	private:
		bool ai_behavior()
		{
			float bust_chance = dealers_hand / 21.00;
			bust_chance = bust_chance * 100.00;
			int d_impulse = rand() % 100 + 1;
			cout << "bust chace is " << bust_chance << " impulse is" << d_impulse << endl;
			if (dealers_hand < 14)
			{
				d_impulse += ((21 - dealers_hand) * 2);
			}
			if (dealers_hand >= 14)
			{
				if (bust_chance > d_impulse)
				{
					return false;
				}
			}
			return true;
		}

		int card_value(int carddrawn)
		{
			int card_value;
			switch (carddrawn)
			{
			case 1:
				{
					int d_hand_check;
					d_hand_check = dealers_hand;
					d_hand_check += 11;
					if (d_hand_check > 21)
					{
						card_value = 1;
						return 1;
						break;
					}
					card_value = 11;
					return card_value;
				}
			case 11:
				return card_value = 10;
				break;
			case 12:
				return card_value = 10;
				break;
			case 13:
				return card_value = 10;
				break;
			default:
				card_value = carddrawn;
			}
			return card_value;
		}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};

#endif