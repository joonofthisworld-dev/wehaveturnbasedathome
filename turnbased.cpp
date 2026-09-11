#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include "Random.h"
#include "Spells.h"
#include "Enemy.h"
#include "Hero.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;


Enemy skelly("Skeleton", 999, 999);


void Battle(Hero player, Enemy enemy)
{
	cout << "You encounter a enemy!" << endl;

	while (player.Alive && enemy.Alive)
	{
		enemy.Display();

		int choice;
		
		cout << "1. Attack" << endl;

		cout << "2. Spells" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:

			enemy.TakeDamage(player.GetDamage());

			break;

		case 2:

			int spellchoice;

			FindSpells();

			cin >> spellchoice;

			switch (spellchoice)
			{
			case 1:
				cout << "Magic does not exist!!!" << endl;
				break;
			case 2:
				cout << "Magic does not exist!!!" << endl;
				break;
			case 3:
				cout << "Magic does not exist!!!" << endl;
				break;

			default:
				cout << "Magic does not exist!!!" << endl;
				break;
			}
		}
	}
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

		Battle(player, skelly);

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
