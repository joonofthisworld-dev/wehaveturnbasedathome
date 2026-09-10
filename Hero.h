#pragma once

#include <iostream>
#include "Screen.h"
#include <cstdlib>

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

	bool alive = true;

	Hero() {
		Name = "Unkown";

		Level = 1;

		Health = 5;
		Endurance = 5;
		Attack = 5;
		Luck = 5;
		Magic = 5;
		Extra = 0;

		Mana = 100,
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


	void ShowPlayerStats()
	{
		cout << "Level " << Level << endl;

		cout << "Health " << Health << endl;
		cout << "Endurance " << Endurance << endl;
		cout << "Attack " << Attack << endl;
		cout << "Luck " << Luck << endl;
		cout << "Magic " << Magic << endl;
		cout << "Extra " << Extra << endl;

		cout << "Mana " << Mana << endl;
		cout << "Health " << CurrentHealth << endl;
	}

	int GetDamage()
	{
		return Attack;
	}

	void Rest()
	{
		if (CanRest)
		{
			CurrentHealth = MaxHealth;
			Mana = MaxMana;
			CanRest = false;

			cout << endl;
			cout << "Rested" << endl;
		}
		else
		{
			cout << endl;
			cout << "Cant Rest!" << endl;
		}
	}
	
	void ResetRest()
	{
		CanRest = true;
	}

	void CastSpell()
	{

	}
	int GetHp()
	{
		return CurrentHealth;
	}
};