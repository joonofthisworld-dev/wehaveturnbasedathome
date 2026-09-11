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

	Enemy(string name, int health, int damage)
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

//add spawn enemy fucntion