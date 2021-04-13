#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	CopyCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();


};