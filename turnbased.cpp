#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include "Random.h"
#include "Spells.h"
#include "Enemy.h"
#include "Screens.h"
#include "Hero.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;



void FightEnemy(Enemy enemy, int damage)
{
	enemy.TakeDamage(damage);
}



int main() 
{

	Hero Player;

	Player.NameHero();

	
	

	MainScreen();


	return 0;
}
