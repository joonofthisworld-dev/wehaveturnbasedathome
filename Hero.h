#pragma once

#include <iostream>
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

	Weapon weapon = Daggers;

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

	bool Alive = true;

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
			MaxMana = 100,
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
			cout << "You died!" << endl;
			Alive = false;
		}


	}


	void ShowPlayerStats()
	{
		cout << endl;
		cout << "Level " << Level << endl;
		cout << endl;
		cout << "Health " << Health << endl;
		cout << "Endurance " << Endurance << endl;
		cout << "Attack " << Attack << endl;
		cout << "Luck " << Luck << endl;
		cout << "Magic " << Magic << endl;
		cout << "Extra " << Extra << endl;
		cout << endl;
		cout << "Mana " << Mana << endl;
		cout << "Health " << CurrentHealth << endl;
		cout << endl;

	}

	int GetDamage()
	{
		int attack = 0;

		switch ( weapon )
		{
		case Daggers:

			attack = Attack;

			break;
		case Sword:

			attack = Attack;
			break;
		case SwordBigger:

			attack = Attack * 3;

			break;
		}


		int outcome = random(1, 5);

		if (outcome == 1)
		{
			attack = 0;
		}

		return attack;
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

	void ChooseWeapon()
	{
		int choice;
		cout << "Chose your weapon!" << endl;

		cout << "1. Daggers" << endl;
		cout << "2. Sword" << endl;
		cout << "3. Sword(Bigger)" << endl;

		cin >> choice;

		switch ( choice)
		{
		case 1:
			weapon = Daggers;
			break;
		case 2:
			weapon = Sword;
			break;
		case 3:
			weapon = SwordBigger;
			break;
		}
	}

	int GetHp()
	{
		return CurrentHealth;
	}

};