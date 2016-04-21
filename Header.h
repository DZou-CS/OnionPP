#pragma once
#ifndef score_h
#define score_h

class game_score
{
public:
	int dealers_bank;
	int players_bank;
	int bet_amount;
	int get_bet(int bet) { return bet_amount; }
private:
	int players_bet;
};
#endif // !score_h
