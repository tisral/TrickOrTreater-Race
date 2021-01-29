/* Israel Tshitenge 1001642997 */

/* CSE 1325 - Coding Assignment 6 */

#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <vector>
#include <sstream>
#include <mutex>
#include "TrickOrTreater.h"

int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string TOTName, std::vector<House*> setOfHouses)
: name{TOTName}, ListOfHouses{setOfHouses}
{
	
}
std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	
	delete TOTThreadPtr; 
}

void TrickOrTreater::GoTrickOrTreating()
{
	int counter = 0;
	for(auto *it: ListOfHouses) 
	{	
		counter++;
		
		Walk((rand()%500)+1); 
		
		std::string candyChosen = it->ringDoorbell(path);
		
		Bucket.insert(make_pair(candyChosen, Bucket[candyChosen]++)); //This Overrride the Bucket to find the item and increase it number
		// Bucket[candyChosen] return 0 when the candy was not found
		
		if(counter == ListOfHouses.size())
		TrickOrTreater::ImDone++;
	}
}

void TrickOrTreater::Walk(int speed)
{
	for(int i = 0; i < 10; i++)
	{
		path << ".";
		std::this_thread::sleep_for (std::chrono::milliseconds(speed));
	}
	
}

std::string TrickOrTreater::getPath()
{
	return path.str();
}

