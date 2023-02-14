#include "games/roulette.hpp"

int main()
{
	Roulette ro(10, 10000);
	int player = 1;
	ro.place_bet_1st_half(10, player);
	ro.place_bet_1st_half(20, player);
	ro.place_bet_2nd_half(80, player);
	ro.place_bet_1st_third(20, player);
	ro.spin();
	ro.place_bet_1st_third(20, player);
	ro.place_bet_red(20, player);
	for (int i = 0; i < 30; i++)
		ro.place_bet_single(200, i, player);
	ro.spin();
	return 0;
}
