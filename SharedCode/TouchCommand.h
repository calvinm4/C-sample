#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
	AbstractFileFactory* filefac;
public:
	TouchCommand(AbstractFileSystem * a, AbstractFileFactory* b);
	int execute(std::string);
	void displayInfo();


};