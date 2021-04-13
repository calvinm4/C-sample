#include "MacroCommand.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

MacroCommand::MacroCommand(AbstractFileSystem* a)
{
}

int MacroCommand::execute(std::string hello)
{
	std::vector<std::string> temp1 = parser->parse(hello);	//string is parsed with correct parser, command vector and parsed vector are looped through and executed
	for (unsigned int i = 0; i < vec.size(); i++) {
		int tempint = vec[i]->execute(temp1[i]);
		if (tempint != 0) {
			return 1;
		}
	}
	return 0;
	
}

void MacroCommand::displayInfo()
{
}

void MacroCommand::addCommand(AbstractCommand* a) // command added to macro
{
	vec.push_back(a);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* b) // parse strategy setting method
{
	parser = b;
}