#pragma once
#include "AbstractParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	std::vector<std::string> parse(std::string);
};