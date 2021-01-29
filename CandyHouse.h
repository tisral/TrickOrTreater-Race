/* Israel Tshitenge 1001642997 */

/* CSE 1325 - Coding Assignment 6 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include "House.h"

#ifndef _CANDY_H
#define _CANDY_H
	
	class CandyHouse : public House
	{
		public :
		
		CandyHouse(std::string, std::map<int, std::string>);
		~CandyHouse();
		std::string ringDoorbell(std::ostringstream &); 
	};
	
#endif	

