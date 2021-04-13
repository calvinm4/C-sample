#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	CatCommand(AbstractFileSystem* a);
	int execute(std::string);
	void displayInfo();


};