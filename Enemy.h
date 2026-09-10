#pragma once

#include <iostream>
#include "Hero.h"
#include "Random.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


// Define Enemy
enum EnemyTypes 
{
	Skelton,
	Goblin,
	Terry,
	Seth
};

class Enemy
{
private:
	string Name;

	// Stats

	int
		Health,
		Damage;


public:

	void TakeDamage(int damage)
	{
		Health -= damage;

		if (Health <= 0)
		{
			cout << "Enemy defeated!" << endl;
			//MainScreen();
		}
	}

	Enemy()
	{
		Name = "Unknown";

		Health = 10;
		Damage = 5;

	}

	Enemy(string name, int health, int damage)
	{
		Name = name;

		Health = health;
		Damage = damage;

	}

	void EnemyAction(Hero player)
	{
		int choice = random(1, 2);

		switch (choice)
		{
		case 1:

			player.TakeDamage(700);

			break;

		case 2:
			cout << "Nothing Happened" << endl;
			break;


		}

	}

	int CheckHealth()
	{
		return Health;
	}
};

