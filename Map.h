#pragma once

#include <iostream>
#include <array> 
#include "Random.h"

using std::cout;
using std::cin;
using std::string;

const int mapsize = 10;

string Map[mapsize][mapsize];

string AvaliableRooms[5] = { "Empty", "Enemy", "Rest", "Shop", "Boss" };


string RandomRoom()
{
	string room;

	int AvailableRoom = random(0, 10);

	if (AvailableRoom < 5)
	{
		room = "Enemy";
	}
	else if (AvailableRoom < 7)
	{
		room = "Rest";
	}
	else if (AvailableRoom < 8)
	{
		room = "Shop";
	}
	else if (AvailableRoom < 9)
	{
		room = "Boss";
	}
	else
	{
		room = "Empty";
	}
	return room;
}

void Generatemap()
{
	for (int i = 0; i < mapsize; ++i)
	{
		for (int j = 0; j < mapsize; ++j)
		{
			Map[i][j] = RandomRoom();

			//cout << Map[i][j] << endl;
		}
	}
}

int currentX = mapsize/2;
int currentY = mapsize/2;

string GetPosition(string map)
{
	cout << "You are current on " << "[" << currentX << "]" << "[" << currentY << "] " << endl;

	string Pos = Map[currentX][currentY];

	return Pos;
}

void Move(string Direction)
{

	if (Direction == "North")
	{

		if (currentY != 10)
		{
			cout << "Went north" << endl;


			currentY += 1;
		}
		else
		{

			cout << "There is nothing but void..." << endl;


		}


	}
	else if (Direction == "South")
	{


		if (currentY != 0)
		{
			cout << "Went South" << endl;


			currentY -= 1;
		}
		else
		{

			cout << "There is nothing but void..." << endl;


		}


	}
	else if (Direction == "East")
	{

		if (currentX != 10)
		{
			cout << "Went east" << endl;


			currentX += 1;
		}
		else
		{

			cout << "There is nothing but void..." << endl;


		}

	}
	else if (Direction == "West")
	{
		if (currentX != 0)
		{
			cout << "Went west" << endl;


			currentX -= 1;
		}
		else
		{

			cout << "There is nothing but void..." << endl;


		}
	}
	else
	{

		cout << "???" << endl;

	}
}


