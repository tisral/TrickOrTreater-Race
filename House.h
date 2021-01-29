/* Israel Tshitenge 1001642997 */

/* CSE 1325 - Coding Assignment 6 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#ifndef _HOUSE_H
#define _HOUSE_H

class House
{
	public :
		House(std::string);
		virtual ~House();
		virtual std::string ringDoorbell(std::ostringstream &); 

	protected:
	
		std::string houseName;
		std::mutex door;
		std::map<int,std::string>CandyRankingMap;
};

#endif	