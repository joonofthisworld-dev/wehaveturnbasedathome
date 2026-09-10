#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


// Define Enemy
string Enemies[4] =
{
	"Skelton",
	"Goblin",
	"Terry"
	"Seth"
};

class Enemy
{
private:
	string Name;

	// Stats

	int
		Health,
		Damage,
		Defense,
		Dodge;


public:

	void TakeDamage(int damage)
	{
		Health -= damage;

		if (Health <= 0)
		{
			cout << "Enemy defeated!" << endl;
		}
	}

	Enemy()
	{
		Name = "Unknown";

		Health = 10;
		Damage = 5;
		Defense = 3;
		Dodge = 5;
	}

	Enemy(string name, int health, int damage, int defense, int dodge)
	{
		Name = name;

		Health = health;
		Damage = damage;
		Defense = defense;
		Dodge = dodge;

	}

};

void EnemyThing()
{
	// Enemy action based off of random
}