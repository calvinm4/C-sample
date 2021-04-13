#include "RenameParsingStrategy.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string hello)
{
	std::vector<std::string> tempVec;
	tempVec.push_back(hello);
	std::istringstream ss(hello);
	std::string temp2;
	if (ss >> temp2) {
		tempVec.push_back(temp2); // user inputted string is put into a string stream and words are pulled out one by one, placed into a vector
	}
	return tempVec;
}
