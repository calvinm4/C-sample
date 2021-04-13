#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include <vector>

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
	std::vector<AbstractCommand*> vec;
	AbstractParsingStrategy* parser;
public:
	MacroCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};