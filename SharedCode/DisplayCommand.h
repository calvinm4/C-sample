#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	DisplayCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();


};