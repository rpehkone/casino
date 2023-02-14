#pragma once
#include <vector>

class PlayerRegistry {
	public:

		void add_player(int player_id)
		{
			player_account_t newp;
			newp.money = 0;
			newp.player_id = player_id;
			players.push_back(newp);
		}

		void player_add_money(float money, int player_id)
		{
			for (int i = 0; i < players.size(); i++)
				if (players[i].player_id == player_id){
					players[i].money += money;return;}
		}
		float get_player_money(int player_id)
		{
			for (int i = 0; i < players.size(); i++)
				if (players[i].player_id == player_id){
					return players[i].money;}
			return 0;
		}

		// true if had enough money
		bool player_reduce_money(float money, int player_id)
		{
			for (int i = 0; i < players.size(); i++)
			{
				if (players[i].player_id == player_id)
				{
					if (players[i].money >= money)
					{
						players[i].money -= money;
						return true;
					}
					return false;
				}
			}
			return false;
		}
		bool is_player_connected(int player_id)
		{
			for (int i = 0; i < players.size(); i++)
				if (players[i].player_id == player_id)
					return true;
			return false;
		}
	private:
		struct player_account_t {
			float money;
			int player_id;
		};
		std::vector<player_account_t> players;
};
