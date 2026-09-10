#pragma once

#include <iostream>
#include "Spells.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


// Game Over Screen
int GameOver()
{
	cout << "Game Over" << endl;
	return 0;
}

void BattleScreen(Hero player, Enemy enemy)
{


	// Spawn enemy

	cout << "You encounter an enemy!" << endl;

	EnemyThing(player, enemy);
	//Blah B;ah Blah
}


void MainScreen()
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
		// Enemy Function
		cout << endl;
		BattleScreen();
		cout << endl;

		break;

	case 2:
		// Spells Function
		cout << endl;
		FindSpells();
		cout << endl;
		MainScreen();
		break;

	case 3:
		// Stats Function

		break;

	case 4:
		// Rest Function
		break;
	}


}
