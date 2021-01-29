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

House :: House(std::string houseName = ""):houseName{houseName} 
{
	
}

House::~House()
{
	std::cout << "HOUSE\n";
}

std::string House::ringDoorbell(std::ostringstream &path)
{
	
}

