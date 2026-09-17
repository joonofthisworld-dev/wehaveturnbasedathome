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
	Seth,
	Bandit
};

class Enemy
{
private:
	string Name;

	// Stats

	float
		Health,
		Damage;


public:

	bool Alive = true;



	void TakeDamage(float damage)
	{
		Health -= damage;

		if (Health <= 0)
		{
			cout << "Enemy defeated!" << endl;
			
			Alive = false;
		}
	}

	Enemy()
	{
		Name = "Unknown";

		Health = 10;
		Damage = 5;

	}

	Enemy(string name, float health, float damage)
	{
		Name = name;

		Health = health;
		Damage = damage;

	}

	float GetDamage()
	{
		float damage = Damage;

		int outcome = random(1, 5);

		if (outcome == 1)
		{
			damage = 0;
		}

		return damage;
	}
	void Display()
	{
		cout << Name << endl << "Health: " << Health << endl;
	}
};

Enemy GenerateEnemy()
{
	int choice = random(1, 5);

	switch (choice)
	{
	case 1:

		return Enemy("Skeleton", 80, 5);

		break;
	case 2:

		return Enemy("Goblin", 30, 10);

		break;
	case 3:

		return Enemy("Bandit", 80, 20);

	case 4:
		return Enemy("Terry", 10000000, 3);

		break;
	case 5:

		return Enemy("Seth", 3, 10000000000);

		break;

		break;
	}
}

//Enemy GenerateBoss()
//{
//	int choice = random(1, 2);
//
//	switch (choice)
//	{
//	case 1:
//		return Enemy("Terry", 10000000, 3);
//
//		break;
//	case 2:
//
//		return Enemy("Seth", 3, 10000000000);
//
//		break;
//
//	}
