#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	LSCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();
};