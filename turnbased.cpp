#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include "Random.h"
#include "Spells.h"
#include "Enemy.h"
#include "Hero.h"
#include "Screen.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


Enemy skelly("Skeleton", 999, 999);



void BattleScreen(Hero player, Enemy enemy)
{
	int ActionChoice;
	int SpellChoice;


	cout << endl;

	cout << "You encounter an enemy! What will you do?" << endl;

	cout << "1. Attack" << endl;

	cout << "2. Spells" << endl;

	cin >> ActionChoice;

	switch (ActionChoice)
	{
	case 1:

		enemy.TakeDamage(player.GetDamage());

		cout << "You Attacked it!" << endl;

		if (enemy.CheckHealth() > 0)
		{
			BattleScreen(player, enemy);
		}
		else
		{
			cout << "You win" << endl;
		}

		break;

	case 2:

		cout << "What spell will you use?" << endl;

		cin >> SpellChoice;

		cout << "Magic does not exist" << endl;
		break;


	}

	player.ResetRest();



	cout << endl;


}

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


int main() 
{

	Hero Player;

	Player.NameHero();

	
	

	MainScreen(Player);


	return 0;
}
