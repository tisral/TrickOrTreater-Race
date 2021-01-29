#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include "House.h"
#include "TrickOrTreater.h"
#include "ToothbrushHouse.h"
#include "CandyHouse.h"

using namespace std;

void get_command_line_params(int argc, char *argv[], string &treaterNamesFile, string &houseNamesFile, string &candyRankingsFile)
{
	if (argv[1] != nullptr && argv[2] != nullptr && argv[3] != nullptr)
	{
		treaterNamesFile = argv[1];
		houseNamesFile = argv[2];
		candyRankingsFile = argv[3];
	}

	else
	{
		throw invalid_argument("Missing command line parameters – - Usage : TrickOrTreaterFile  HouseFile  CandyRankingsFile");
	}
}

std::ostream &operator<<(std::ostream &output, TrickOrTreater &individualTOTer)
{
	output << individualTOTer.getName() << " - ";

	for (auto it : individualTOTer.Bucket)
	{
		output << it.second << " " << it.first << ", ";
	}

	output << "\n";

	return output;
}

int main(int argc, char *argv[])
{
	map<int, string> candyRankings;
	vector<House *> setOfHouses;
	vector<TrickOrTreater> TOTs; // can also be a vector of pointers

	stringstream houseListToDisplay;

	string treaterNamesFile;
	string houseNamesFile;
	string candyRankingsFile;

	char singlelineChar[20];
	char *Token;
	char Delimiters[2] = {"|"};

	string candysName;
	string singleLine;

	int ranking;
	int next = 10;
	srand(time(NULL)); //The reandm number generator should be in main

	try
	{
		get_command_line_params(argc, argv, treaterNamesFile, houseNamesFile, candyRankingsFile);
	}
	catch (invalid_argument &say)
	{
		cout << "\n\n"
			 << say.what() << "\n\n";
		exit(0);
	}

	ifstream fileHandler1{candyRankingsFile};
	ifstream fileHandler2{houseNamesFile};
	ifstream fileHandler3{treaterNamesFile};

	if (fileHandler1.is_open() && fileHandler2.is_open() && fileHandler3.is_open())
	{
		while (getline(fileHandler1, singleLine))
		{
			strcpy(singlelineChar, singleLine.c_str());

			Token = strtok(singlelineChar, Delimiters);
			candysName = Token;

			Token = strtok(NULL, Delimiters);
			ranking = atoi(Token);

			candyRankings.insert(make_pair(ranking, candysName));
		}
		fileHandler1.close();

		while (getline(fileHandler2, singleLine))
		{
			if ((rand() % 100) % 2)
			{
				setOfHouses.push_back(new CandyHouse(singleLine, candyRankings));
			}

			else
			{
				setOfHouses.push_back(new ToothbrushHouse(singleLine));
			}

			for (int i = 0; i < next; i++)
			{
				houseListToDisplay << " ";
			}

			houseListToDisplay << singleLine;

			next = 11 - singleLine.size();
		}
		fileHandler2.close();

		while (getline(fileHandler3, singleLine))
		{
			TOTs.push_back(TrickOrTreater(singleLine, setOfHouses)); //the orignal object is destoyed just everytime. can also use "new"
		}
		fileHandler3.close();
	}

	else
	{
		cout << "\n\nUnable to open at least one input file\n\n";
		exit(0);
	}

	for (auto &it : TOTs) //by reference, or by using *
	{
		it.startThread();
	}

	while (TrickOrTreater::ImDone != TOTs.size())
	{
		for (int i = 0; i < 34; i++)
		{
			cout << "\n";
		}

		cout << houseListToDisplay.str() << "\n\n";

		for (auto &it : TOTs)
		{
			cout << it.getPath() << it.getName() << "\n\n";
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}

	for (auto &it : TOTs)
	{
		it.joinThread();
	}

	cout << "\n\n";

	for (auto &it : TOTs)
	{
		cout << it;
	}

	for (auto *it : setOfHouses)
	{
		delete it;
	}

	return 0;
}
