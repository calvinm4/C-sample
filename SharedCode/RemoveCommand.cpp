#include "RemoveCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* a) : filesys(a)
{
}

int RemoveCommand::execute(std::string hello) //method to delete file
{
	return filesys->deleteFile(hello); //simply goes and deletes the file from the filesystem
}

void RemoveCommand::displayInfo()
{
	cout << "rm removes the filesystem. The command should be invoked with rm <filename>" << endl;
}
