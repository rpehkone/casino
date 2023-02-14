#include <cstdlib>
#include <stack>
#include <time.h>
#include <iostream>

class RouletteBet {
	float amount;
	int player_id;
};

class RoulettePlayer {
	float money;
	int player_id;
};

class Roulette {
	public:
		Roulette(int set_minimum_bet, int set_maximum_bet)
		{
			get_player_id = 1;
			minimum_bet = set_minimum_bet;
			maximum_bet = set_maximum_bet;
			srand((unsigned)time(0));
		}

		void spin()
		{
			spin_res = rand() % 37;
			std::cout << "got number: " << spin_res << "\n";
			check_results();
		}


		// 0 and singles return x35
		// void place_bet_single(int number, float amount);
		// void place_bet_even();
		// void place_bet_odd();
		// void place_bet_red();
		// void place_bet_black();
		// red = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};

		void place_bet_1st_half(float amount) {place_bet(bets_1st_half, amount);};
		void place_bet_2nd_half(float amount) {place_bet(bets_2nd_half, amount);};
		void place_bet_1st_third(float amount) {place_bet(bets_1st_third, amount);};
		void place_bet_2nd_third(float amount) {place_bet(bets_2nd_third, amount);};
		void place_bet_3rd_third(float amount) {place_bet(bets_3rd_third, amount);};

	private:
		int get_player_id;
		int minimum_bet;
		int maximum_bet;
		int spin_res;

		std::stack<float> bets_1st_half;
		std::stack<float> bets_2nd_half;
		std::stack<float> bets_1st_third;
		std::stack<float> bets_2nd_third;
		std::stack<float> bets_3rd_third;

		void place_bet(std::stack<float>& bets, float betAmount)
		{
			//substract from player
			//check player total bets
			bool isBetAllowed = (bool)(betAmount >= minimum_bet && betAmount <= maximum_bet);
			if (!isBetAllowed)
			{
				std::cout << "bet not allowed\n";
				return;
			}
			bets.push(betAmount);
		}

		void check_results()
		{
			while (!bets_1st_half.empty())
			{
				float bet = bets_1st_half.top();
				if (spin_res > 0 && spin_res < 19)
					std::cout << "bet wins: " << bet * 2.0 << "\n";
				else
					std::cout << "bet loses\n";
				bets_1st_half.pop();
			}
		}
};
