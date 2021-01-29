/* Israel Tshitenge 1001642997 */

/* CSE 1325 - Coding Assignment 6 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>
#include "House.h"

#ifndef _TB_H
#define _TB_H

class ToothbrushHouse : public House
{
	public :
	
		ToothbrushHouse(std::string);
		~ToothbrushHouse();
		std::string ringDoorbell(std::ostringstream &); 
};

#endif

