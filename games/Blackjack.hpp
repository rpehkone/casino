#pragma once
#include <iostream>
#include <vector>
#include <time.h>

#include "PlayerRegistry.hpp"

// https://www.youtube.com/watch?v=eyoh-Ku9TCI

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

		bool place_bet(float bet_amount, int player_id)
		{
		}

		void tick()
		{
			//idle until someone places bet

			//if no-one playing
			{
				blackjack_start();
				//players place bets (10 sec)
					//skip time if everyon placed bet
			}

			//dealer draw
			//player draw
			int dealer_total = 0;
			int player_total = 0;
			if (player_total > 21 || player_total <= dealer_total)
				;//lose
			//everyone 10 sec to place bet (if simulatin irl casino)
			//10 sec to place bet (online)
		}

	private:
		PlayerRegistry* casino;
		int minimum_bet;
		int maximum_bet;

		//represents player in single round
		struct blackjack_bet_t
		{
			std::vector<int> cards;
			int player_id;
		};

		std::vector<int> dealer_cards;
		std::vector<blackjack_bet_t> players;

		//maybe if player doesnt input in whole round its disconnected
		void blackjack_start(void)
		{
		}


		int get_card(void)
		{
			int res = rand() % 13 + 1;
			return res;
		}
};
