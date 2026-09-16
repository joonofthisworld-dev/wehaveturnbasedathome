#pragma once

#include <fstream>
#include <iostream>


std::ofstream GameLog;
std::ifstream HighScore;


void writeToFile(std::string text)
{
	std::ofstream logFile("GameLog.txt");
	if (logFile.is_open())
	{
		logFile << text << std::endl;

		logFile.close();

		std::cout << "File written successfully" << std::endl;
	}
	else
	{
		std::cout << "Error: Could not create file!" << std::endl;

	}
}



void appendToLog(std::string file ,std::string text)
{
	std::ofstream logFile(file, std::ios::app);

	if (logFile.is_open())
	{
		logFile << text << std::endl;

		logFile.close();
	}
}

void AddScore(string name, int level)
{
	std::ofstream logFile("GameScore.txt");

	if (logFile.is_open())
	{
		logFile << name << std::endl << level << std::endl;

		logFile.close();
	}
}

void readFromFile()
{
	std::ifstream datafile("GameScore.txt");

	if (datafile.is_open())
	{
		string playername;

		int playerlevel;

		datafile >> playername >> playerlevel;

		cout << playername << endl << "Level: " <<  playerlevel << endl;

		datafile.close();
	}

	else
	{
		cout << "No data found" << endl;
	}
	
}