#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cassert>


#include "Random.h"
#include "Spells.h"
#include "Enemy.h"
#include "Hero.h"
#include "Files.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;

int cycle = 1;


Enemy function5()
{
	return GenerateEnemy();
}

void Battle(Hero& player, Enemy enemy)
{
	cout << endl;
	cout << "You encounter a enemy!" << endl;

	while (player.Alive && enemy.Alive)
	{
		cout << endl;
		enemy.Display();
		cout << endl;
		player.DisplayBattle();
		cout << endl;

		int choice;
		
		cout << "1. Attack" << endl;

		cout << "2. Spells" << endl;

		cout << "3. Inventory" << endl;

		cin >> choice;
		if (cin.fail())
		{
			cout << "use numbers";
			cin.clear();
			cin.ignore();
			
			continue;
		}

		cout << endl;

		switch (choice)
		{
		case 1:

			enemy.TakeDamage(player.GetDamage());

			cout << "You took " << enemy.GetDamage() << " Damage" << endl;

			if (player.Alive)
			{
				player.TakeDamage(enemy.GetDamage());

				cout << "The enemy took " << player.GetDamage() << " Damage" << endl;
			}

			

			break;

		case 2:

			int spellchoice;

			FindSpells();

			cin >> spellchoice;

			if (cin.fail())
			{
				cout << "use numbers";
				cin.clear();
				cin.ignore();

				continue;
			}

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

			case 4:

				cout << "Magic does not exist!!!" << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());

				break;

			case 5:


				cout << "I lied theres no spell." << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());


				break;
			case 6:
				cout << "You casted it on yourself!!!" << endl;

				player.ManaChange(-67);

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());
			break;

			default:
				cout << "Magic does not exist!!!" << endl;

				cout << "You took " << enemy.GetDamage() << " Damage" << endl;
				player.TakeDamage(enemy.GetDamage());
				break;
			}
			break;

		case 3:
			int invuse;

			player.ViewInventory();

			cin >> invuse;

			switch (invuse)
			{

			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:

				invuse -= 1;

				if (player.inventory[invuse] == "potion")
				{
					cout << "You took a potion..." << endl;

					player.inventory[invuse] = "empty";

					player.Heal(20);
				}
				else if (player.inventory[invuse] == "poison")
				{
					cout << "You took poison..." << endl;

					player.inventory[invuse] = "empty";

					player.TakeDamage(20);
				}
				else
				{
					cout << "Nothing happened..." << endl;
				}

				break;

			default:
				break;
			}
			break;
		}
	}

	if (player.Alive && enemy.Alive == false)
	{

		int reward = random(1,3);

		cout << endl;
		cout << "You win!" << endl;

		appendToLog("Gamelog.txt","Enemy Defeated!");

		if (reward == 1)
		{
			int choice;

			cout << "The enemy dropped a potion would you like to store it?" << endl << "1. Yes" << "2. No" << endl;

			cin >> choice;

			if (choice == 1)
			{
				int slot;

				player.ViewInventory();
				cout << "Which slot?" << endl;

				cin >> slot;

				switch (slot)
				{
					slot -= 1;
					case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:

						player.inventory[slot] = "potion";

				}
			}
		}
		else if (reward == 2)
		{
			int choice;

			cout << "The enemy dropped a posion would you like to store it?" << endl << "1. Yes" << "2. No" << endl;

			cin >> choice;

			if (choice == 1)
			{
				int slot;

				player.ViewInventory();
				cout << "Which slot?" << endl;

				cin >> slot;

				switch (slot)
				{
					slot -= 1;
				case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:

					player.inventory[slot] = "poison";

				}
			}
		}

		player.Upgrade();

		cycle += 1;
	}
	else if (player.Alive == false && enemy.Alive)
	{
		cout << endl;
		cout << "You loose." << endl;
	}

	player.ResetRest();
}

void MainScreen(Hero player)
{


	while (player.Alive)
	{
		cout << cycle << endl; 

		int choice = 1;

		cout << endl;

		cout << "What would you like to do?" << endl;

		cout << "1. Fight Enemy" << endl;

		cout << "2. View Spells" << endl;

		cout << "3. View Stats" << endl;

		cout << "4. Rest" << endl;

		cout << "5. View Inventory" << endl;

		cout << "6. Previous Run" << endl;

		cin >> choice;

		if (cin.fail())
		{
			cout << "use numbers";
			cin.clear();
			cin.ignore();

			continue;
		}


		switch (choice)
		{

		case 1:

			Battle(player, function5());

			continue;

			break;

		case 2:
			// Spells Function

			cout << endl;

			FindSpells();

			cout << endl;

			continue;

			break;

		case 3:

			player.ShowPlayerStats();

			continue;
			break;

		case 4:

			player.Rest();

			continue;
			break;

		case 5:

			player.ViewInventory();

			continue;
			break;

		case 6:

			readFromFile();

			continue;
			break;
		}
	}
}


int main() 
{


	writeToFile("Game Started!");

	Hero Player;

	Player.NameHero();

	Player.ChooseWeapon();


	MainScreen(Player);

	appendToLog("Gamelog.txt", "Game Ended!");

	AddScore(Player.GetName(), Player.GetLevel());

	return 0;
}

