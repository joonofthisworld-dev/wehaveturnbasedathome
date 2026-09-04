#include <iostream>
#include <random>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;


// Game Over Screen
int GameOver()
{
	cout << "Game Over" << endl;
	return 0;
}



// Define Player/Class
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

	void DamageHero(int damage)
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
};

// Define Enemy

class Enemy
{
private:
	string name;

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

};


void MainScreen()
{
	int choice = 1;
	
	cout << "What would you like to do?" << endl;

		cout << "1. Fight Enemy" << endl;

		cout << "2. View Spells" << endl;

		cout << "3. View Stats" << endl;

		cout << "4. Rest" << endl;

		cin >> choice;


		switch (choice)
		{

			case 1:
				// Enemy Function
			break;

			case 2:
				// Spells Function
			break;

			case 3:
				// Stats Function
				break;

			case 4:
				// Rest Function
				break;
		}


}

int main() 
{

	Hero Player();

	Player().NameHero();
	

	MainScreen();


	return 0;
}
