#include <iostream>
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

		//returns true if bet was placed
		bool place_bet_1st_half(float amount, int player_id)	{return place_bet(amount, player_id, 0);};
		bool place_bet_2nd_half(float amount, int player_id)	{return place_bet(amount, player_id, 1);};
		bool place_bet_1st_third(float amount, int player_id)	{return place_bet(amount, player_id, 2);};
		bool place_bet_2nd_third(float amount, int player_id)	{return place_bet(amount, player_id, 3);};
		bool place_bet_3rd_third(float amount, int player_id)	{return place_bet(amount, player_id, 4);};
		bool place_bet_single(float amount, int number, int player_id) {return place_bet(amount, player_id, 5, number);};
		bool place_bet_even(float amount, int player_id)		{return place_bet(amount, player_id, 6);};
		bool place_bet_odd(float amount, int player_id)			{return place_bet(amount, player_id, 7);};
		bool place_bet_red(float amount, int player_id)			{return place_bet(amount, player_id, 8);};
		bool place_bet_black(float amount, int player_id)		{return place_bet(amount, player_id, 9);};

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

		bool place_bet(float bet_amount, int player_id, int bet_category, int single_bet_value = 0)
		{
			//instead check player total bets
			bool is_bet_allowed = (bool)(bet_amount >= minimum_bet && bet_amount <= maximum_bet);
			if (single_bet_value < 0 || single_bet_value > 36)
				is_bet_allowed = false;

			if (!is_bet_allowed)
			{
				std::cout << "bet not allowed\n";
				return false;
			}
			RouletteBet newbet;
				newbet.amount = bet_amount;
				newbet.player_id = player_id;
				newbet.bet_category = bet_category;
				newbet.single_bet_value = single_bet_value;

			current_bets.push_back(newbet);
			return true;
		}

		float cat0(RouletteBet bet) {//1st half
			return (spin_res >= 0 && spin_res <= 18) ? bet.amount * 2.0f : 0;}
		float cat1(RouletteBet bet) {//2nd half
			return (spin_res >= 19 && spin_res <= 36) ? bet.amount * 2.0f : 0;}
		float cat2(RouletteBet bet) {//1st third
			return (spin_res >= 1 && spin_res <= 12) ? bet.amount * 3.0f : 0;}
		float cat3(RouletteBet bet) {//2nd third
			return (spin_res >= 13 && spin_res <= 24) ? bet.amount * 3.0f : 0;}
		float cat4(RouletteBet bet) {//3rd third
			return (spin_res >= 25 && spin_res <= 36) ? bet.amount * 3.0f : 0;}
		float cat5(RouletteBet bet) {//single
			return (bet.single_bet_value == spin_res) ? bet.amount * 36.0f : 0;}
		float cat6(RouletteBet bet) {//even
			if (spin_res == 0)
				return 0;
			return (spin_res % 2 == 0) ? bet.amount * 2.0f : 0;}
		float cat7(RouletteBet bet) {//odd
			return (spin_res % 2 != 0) ? bet.amount * 2.0f : 0;}
		float cat8(RouletteBet bet) {//red
			float red[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 21, 23, 25, 27, 30, 32, 34, 36};
			return (std::find(std::begin(red), std::end(red), spin_res) != std::end(red)) ? bet.amount * 2.0f : 0;}
		float cat9(RouletteBet bet) {//black
			float black[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
			return (std::find(std::begin(black), std::end(black), spin_res) != std::end(black)) ? bet.amount * 2.0f : 0;}

		float (Roulette::*bet_check_result[100])(RouletteBet) = {&Roulette::cat0, &Roulette::cat1, &Roulette::cat2, &Roulette::cat3,
								&Roulette::cat4, &Roulette::cat5, &Roulette::cat6, &Roulette::cat7, &Roulette::cat8, &Roulette::cat9};

		//return array of how much players won
		void check_results()
		{
			for (size_t i = 0; i < current_bets.size(); i++)
			{
				RouletteBet bet = current_bets[i];
				float res = (this->*bet_check_result[bet.bet_category]) (bet);
				if (res)
					std::cout << bet.bet_category << " won: " << res << "$\n";
			}
			current_bets.resize(0);
		}
};
