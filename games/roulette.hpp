#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

class Roulette {
	public:
		Roulette(int set_minimum_bet, int set_maximum_bet)
		{
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

		//returns if bet was placed
		bool place_bet_1st_half(float amount, int player_id) {return place_bet(amount, player_id, 0);};
		bool place_bet_2nd_half(float amount, int player_id) {return place_bet(amount, player_id, 1);};
		bool place_bet_1st_third(float amount, int player_id) {return place_bet(amount, player_id, 2);};
		bool place_bet_2nd_third(float amount, int player_id) {return place_bet(amount, player_id, 3);};
		bool place_bet_3rd_third(float amount, int player_id) {return place_bet(amount, player_id, 4);};

		// 0 and singles return x35
		// void place_bet_single(int number, float amount);
		// void place_bet_even();
		// void place_bet_odd();
		// void place_bet_red();
		// void place_bet_black();
		// red = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};

	private:

		struct RouletteBet {
			float amount;
			int player_id;
			int bet_category;
			int single_bet_value;
		};

		std::vector<RouletteBet> current_bets;
		int minimum_bet;
		int maximum_bet;
		int spin_res;

		bool place_bet(float bet_amount, int player_id, int bet_category)
		{
			//instead check player total bets
			bool is_bet_allowed = (bool)(bet_amount >= minimum_bet && bet_amount <= maximum_bet);
			if (!is_bet_allowed)
			{
				std::cout << "bet not allowed\n";
				return false;
			}
			RouletteBet newbet;
				newbet.amount = bet_amount;
				newbet.player_id = player_id;
				newbet.bet_category = bet_category;

			current_bets.push_back(newbet);
			return true;
		}

		float cat0(float bet_amount) {//1st half
			return (spin_res >= 0 && spin_res <= 18) ? bet_amount * 2.0f : 0;}
		float cat1(float bet_amount) {//2nd half
			return (spin_res >= 19 && spin_res <= 36) ? bet_amount * 2.0f : 0;}
		float cat2(float bet_amount) {//1st third
			return (spin_res >= 1 && spin_res <= 12) ? bet_amount * 3.0f : 0;}
		float cat3(float bet_amount) {//2nd third
			return (spin_res >= 13 && spin_res <= 24) ? bet_amount * 3.0f : 0;}
		float cat4(float bet_amount) {//3rd third
			return (spin_res >= 25 && spin_res <= 36) ? bet_amount * 3.0f : 0;}

		float (Roulette::*bet_check_result[100])(float) = {&Roulette::cat0, &Roulette::cat1, &Roulette::cat2, &Roulette::cat3, &Roulette::cat4};

		void check_results()
		{
			for (size_t i = 0; i < current_bets.size(); i++)
			{
				RouletteBet bet = current_bets[i];
				float res = (this->*bet_check_result[bet.bet_category]) (bet.amount);
				if (res)
					std::cout << "won: " << res << "$\n";
			}
			current_bets.resize(0);
		}
};
