#pragma once
#include <iostream>
#include <vector>
#include <time.h>

#include "PlayerRegistry.hpp"

class Blackjack
{
	public:
		Blackjack(int set_minimum_bet, int set_maximum_bet, PlayerRegistry* set_casino)
		{
			minimum_bet = set_minimum_bet;
			maximum_bet = set_maximum_bet;
			casino = set_casino;
			srand((unsigned)time(0));
		}

		//join game
		//10 sec to place bet on round start
		//start if everyon placed bet
		//while everyone not lost
			//dealer draw
			//everyone 10 sec to place bet (if simulatin irl casino)
			//10 sec to place bet (online)
	private:
		PlayerRegistry* casino;
		int minimum_bet;
		int maximum_bet;
};
