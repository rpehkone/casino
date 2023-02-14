#include "games/roulette.hpp"

int main()
{
	Roulette ro(10, 10000);
	ro.place_bet_1st_half(10);
	ro.place_bet_1st_half(20);
	ro.place_bet_2nd_half(80);
	ro.place_bet_1st_third(20);
	ro.spin();
	return 0;
}
