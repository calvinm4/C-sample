#include "LSCommand.h"
#include <iostream>
LSCommand::LSCommand(AbstractFileSystem* a) : filesys(a)
{
}

int LSCommand::execute(std::string temp)
{
	if (temp == "-m") { //if user wants the metadata, we use our metadata command to fetch and print it.
		filesys->getFileData();
		return 0;
	}
	if (temp == "") { //otherwise, display the names of the files spaced out.
		filesys->getFileNames();
		return 0; 
	}
	return 1; //returns failure if none of the commands worked
	
}

void LSCommand::displayInfo()
{
	cout << "ls lists all the files stored in your system. You can also invoke it with the command: ls -m to view metadata" << endl;
}

