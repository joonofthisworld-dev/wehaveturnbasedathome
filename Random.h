#pragma once

#include <iostream>
#include <ctime>
#include <random>


int random(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	int randomnum = dist(gen);
	return randomnum;
}
