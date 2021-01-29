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
#include "ToothbrushHouse.h"

ToothbrushHouse :: ToothbrushHouse(std::string houseName)
:House(houseName)
{
	
}

ToothbrushHouse :: ~ToothbrushHouse()
{
	std::cout << "TOOTHBRUSHHOUSE\n";
}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
	door.lock();
	
	path << "-";
	
	std::this_thread::sleep_for (std::chrono::seconds(3));
	
	door.unlock();
	
	return "TOOTHBRUSH";
}

