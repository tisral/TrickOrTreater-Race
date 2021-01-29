/* Israel Tshitenge 1001642997 */

/* CSE 1325 - Coding Assignment 6 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include <time.h>
#include "House.h"
#include "CandyHouse.h"

CandyHouse :: CandyHouse(std::string houseName, std::map<int, std::string> candyRankings)
:House(houseName)
{
	CandyRankingMap = candyRankings;
}

CandyHouse :: ~CandyHouse ()
{
	std::cout << "CANDYHOUSE\n";
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
	door.lock();
	
	path << "+";
	
	std::this_thread::sleep_for (std::chrono::seconds(3));
	
	int candyPicked = 1+rand()%CandyRankingMap.size();
	
	door.unlock();
	
	return CandyRankingMap[candyPicked];
}

