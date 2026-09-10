#pragma once


#include <iostream>
#include "Hero.h"
#include "Enemy.h"

void MainScreen(Hero player)
{


	int choice = 1;

	cout << "What would you like to do?" << endl;

	cout << "1. Fight Enemy" << endl;

	cout << "2. View Spells" << endl;

	cout << "3. View Stats" << endl;

	cout << "4. Rest" << endl;

	cin >> choice;


	switch (choice)
	{

	case 1:

		BattleScreen(player, skelly);

		break;

	case 2:
		// Spells Function

		cout << endl;

		FindSpells();

		cout << endl;

		MainScreen(player);

		break;

	case 3:

		player.ShowPlayerStats();

		MainScreen(player);
		break;

	case 4:

		player.Rest();

		MainScreen(player);
		break;
	}


}

int GameOver()
{
	std::cout << "Game Over" << std::endl;

	return 0;
}

