#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class CommandPrompt {

private:
	std::map <std::string, AbstractCommand*> stringToComm;
	AbstractFileSystem* storageSystem;
	AbstractFileFactory* storageFactory;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();

};
