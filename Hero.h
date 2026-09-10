#pragma once

#include <iostream>
#include "Screens.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Define Player/Class

enum Weapon
{
	Daggers,
	Sword,
	SwordBigger
};

class Hero {

private:

	string Name;

	int
		// Level
		Level,
		MaxExp,
		Exp,

		// Stats
		Health,
		Endurance,
		Attack,
		Luck,
		Magic,
		Extra,

		// Attack

		Mana,
		MaxMana,
		Defense,
		MaxHealth,
		CurrentHealth;


	bool CanRest = true;

public:

	Hero() {
		Name = "Unkown";

		Level = 1;
		MaxExp = 100;
		Exp = 0;

		Health = 0;
		Endurance = 0;
		Attack = 0;
		Luck = 0;
		Magic = 0;
		Extra = 0;

		Mana = 0,
			MaxMana = 0,
			Defense = 5;
		MaxHealth = 100;
		CurrentHealth = 100;
	}

	void NameHero()
	{
		string name;

		cout << "Name your hero" << endl;

		cin >> name;

		Name = name;

		cout << "Ok, " << name << endl;
	}

	void TakeDamage(int damage)
	{
		CurrentHealth -= damage;
		if (CurrentHealth <= 0)
		{
			GameOver();
		}
	}

	void GainExp(int gain)
	{
		Exp += gain;

		if (Exp >= MaxExp)
		{
			cout << "Level up!" << endl;
		}
	}
	void Levelup()
	{
		//bring to level screen and grant stats
	}

	void ShowPlayerStats()
	{
		//cout player stats
	}

	void Rest()
	{
		CurrentHealth = MaxHealth;
		Mana = MaxMana;
		CanRest = false;
	}
};