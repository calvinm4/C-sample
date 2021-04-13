#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	RemoveCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();


};