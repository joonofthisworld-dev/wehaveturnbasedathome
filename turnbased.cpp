#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <Windows.h>
#include <mmsystem.h>


#include "Random.h"
#include "Enemy.h"
#include "Hero.h"
#include "Files.h"
#include "Map.h"
#include "String.h"
#include "Item.h"




using std::string;
using std::cout;
using std::cin;
using std::endl;

int cycle = 1;

Enemy GenEnemy()
{
	return GenerateEnemy();
}

Enemy GenBoss()
{
	return GenerateBoss();
}


void Shop(Hero& player)
{
	bool inshop = true;

	int choice;

	string items[3]{ "Potion","Potion","Potion" };

	while (inshop)
	{
		cout << "You enter the shop..." << endl;
		

		for (int item = 0; item < 3; item++)
		{
			cout << items[item] << endl;
			if (items[item] == "Potion")
			{
				cout << item + 1 << " Potion: 20 Gold" << endl;
			}
			else if (items[item] == "Empty")
			{
				cout << item + 1 << " Empty" << endl;
			}
		}

		cout << " 4. Leave";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (items[0] != "Empty" && player.Money >= 20)
			{
				player.Money -= 20;
				items[0] = "Empty";

				cout << "Bought a potion." << endl;
				cout << "Where would you like to put it?" << endl;

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
			break;
		case 2:
			if (items[1] != "Empty" && player.Money >= 20)
			{
				player.Money -= 20;
				items[1] = "Empty";

				cout << "Bought a potion." << endl;
				cout << "Where would you like to put it?" << endl;

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
			break;
		case 3:
			if (items[2] != "Empty" && player.Money >= 20)
			{
				player.Money -= 20;
				items[2] = "Empty";

				cout << "Bought a potion." << endl;
				cout << "Where would you like to put it?" << endl;

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
			break;
		case 4:
			inshop = false;
			break;

		}
	}
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

			player.FindSpells();

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

			void invUse();
			{
			int invuse;

			HealPotion healpot("Heal Potion", 20);
			Poison poipot("Poison Potion", 20);

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

					healpot.Use(player);
				}
				else if (player.inventory[invuse] == "poison")
				{
					cout << "You took poison..." << endl;

					player.inventory[invuse] = "empty";

					poipot.Use(player);
				}
				else if (player.inventory[invuse] == "water")
				{
					cout << "Stay hydrated" << endl;

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

		 int moneyreward = random(1, 50);

		player.Money += moneyreward;

		cout << "You gained " << moneyreward << " gold!" << endl;

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

void MainScreen(Hero& player)
{


	while (player.Alive)
	{

		int choice = 1;

		cout << endl;

		GetPosition(Map[currentX][currentY]);

		cout << endl;

		cout << "To the north you see a " << Map[currentX][currentY + 1] << " Node" << endl;
		cout << "To the south you see a " << Map[currentX][currentY - 1] << " Node" << endl;
		cout << "To the east you see a " << Map[currentX + 1][currentY] << " Node" << endl;
		cout << "To the west you see a " << Map[currentX - 1][currentY] << " Node" << endl;

		cout << endl;

		cout << "What would you like to do?" << endl;

		cout << "1. Move (N/S/E/W)" << endl;

		cout << "2. View Spells" << endl;

		cout << "3. View Stats" << endl;

		if (Map[currentX][currentY] == "Rest")
		{
		cout << "4. Rest" << endl;
		}

		if (Map[currentX][currentY] == "Shop")
		{
			cout << "5. Shop" << endl;
		}

		cout << "6. View Inventory" << endl;

		cout << "7. Previous Run" << endl;

		cin >> choice;

		

		if (cin.fail())
		{
			cout << "use numbers";

			cin.clear();

			cin.ignore();

			continue;
		}

		string dir;

		switch (choice)
		{

		case 1:

			cout << "Which direction?" << endl;
			
			cin >> dir;

			Move(dir);

			if (Map[currentX][currentY] == "Enemy")
			{
				Battle(player, GenEnemy());
			}
			else if (Map[currentX][currentY] == "Boss")
			{
				Battle(player, GenBoss());
			}

			continue;

			break;

		case 2:
			// Spells Function

			cout << endl;

			player.FindSpells();

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
			Shop(player);

			continue;
			break;
		case 6:

			player.ViewInventory();

			continue;
			break;

		case 7:

			readFromFile();

			continue;
			break;
		}
	}
}



bool funny = false;

int main() 
{


	//// String test part---------------------------------------------------------------

	//StringUtility::ReadFromConsole();

	//writeToFile("Sucessfully stored " + store + "\n", "StringTest.txt");

	//StringUtility::WriteToConsole(store);

	//appendToLog("StringTest.txt", "Wrote " + store + " to the console\n");

	//if (StringUtility::EqualTo(store, "Hello"))
	//{
	//	appendToLog("StringTest.txt",store + " is equal to Hello \n" );
	//}
	//else
	//{
	//	appendToLog("StringTest.txt", store + " is not equal to Hello \n");
	//}

	//appendToLog("StringTest.txt", store + " in lower case is:");

	//store = StringUtility::Tolower(store);

	//appendToLog("StringTest.txt", store);

	//string len = std::to_string(StringUtility::Length(store));

	//appendToLog("StringTest.txt", store + " has a length of " + len + " letters\n");

	//store = StringUtility::Append(store, "blah blah blah append");

	//appendToLog("StringTest.txt", store);

	//readFromFileString();


	//// Main Game part---------------------------------------------------------------



	Hero Player;

	Player.NameHero();

	Player.ChooseWeapon();

	Generatemap();

	MainScreen(Player);

	appendToLog("Gamelog.txt", "Game Ended!");

	AddScore(Player.GetName(), Player.GetLevel());




	return 0;
}

