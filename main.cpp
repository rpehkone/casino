#include "games/PlayerRegistry.hpp"
#include "games/roulette.hpp"
#include "games/Blackjack.hpp"
#include <iostream>

int main()
{
	int pid = 1;
	PlayerRegistry casino;
	casino.add_player(pid);
	casino.player_add_money(5000, pid);

	// std::vector<std::unique_ptr<Roulette>> roulette_tables;
	// roulette_tables.emplace_back(std::make_unique<Roulette>());
	Roulette ro(10, 10000, &casino);

	// ro.place_bet_1st_half(10, pid);
	// ro.place_bet_1st_half(20, pid);
	// ro.place_bet_2nd_half(80, pid);
	// ro.place_bet_1st_third(20, pid);
	// ro.spin();
	// ro.place_bet_1st_third(20, pid);
	// ro.place_bet_red(20, pid);
	for (int i = 0; i < 100; i++)
	{
		// ro.place_bet_red(100, pid);
		ro.place_bet_single(100, 0, pid);
		ro.spin();
		std::cout << "Money: " << casino.get_player_money(pid) << "$\n";
	}
	return 0;
}
