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


Enemy skelly("Skeleton", 20, 1);


void Battle(Hero player, Enemy enemy)
{
	cout << endl;
	cout << "You encounter a enemy!" << endl;

	while (player.Alive && enemy.Alive)
	{
		cout << endl;
		enemy.Display();

		int choice;
		
		cout << "1. Attack" << endl;

		cout << "2. Spells" << endl;

		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:

			enemy.TakeDamage(player.GetDamage());

			cout << "You took " << enemy.GetDamage() << " Damage" << endl;

			player.TakeDamage(enemy.GetDamage());

			cout << "The enemy took " << player.GetDamage() << " Damage" << endl;

			break;

		case 2:

			int spellchoice;

			FindSpells();

			cin >> spellchoice;

			switch (spellchoice)
			{
			case 1:
				cout << "Magic does not exist!!!" << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());


				break;
			case 2:

				cout << "Magic does not exist!!!" << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());

				break;
			case 3:
				cout << "You Expoded!!!" << endl;

				player.TakeDamage(99999999);

				break;

			default:
				cout << "Magic does not exist!!!" << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());
				break;
			}
		}
	}

	if (player.Alive && enemy.Alive == false)
	{
		cout << endl;
		cout << "You win!" << endl;
	}
	else if (player.Alive == false && enemy.Alive)
	{
		cout << endl;
		cout << "You loose." << endl;
	}
}

void MainScreen(Hero player)
{


	int 
		choice = 1;

	cout << endl;

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

		if (player.Alive == true)
		{
			MainScreen(player);
		}
		else
		{

		}
		

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
	Player.ChooseWeapon();

	MainScreen(Player);

	return 0;
}
