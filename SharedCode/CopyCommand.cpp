#include "CopyCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

CopyCommand::CopyCommand(AbstractFileSystem* a) : filesys(a)
{
}

int CopyCommand::execute(std::string hello) //this method will copy a file by taking the old file, and the new file's name, and copying the content of the old file into the new file just created.
{
	istringstream ss(hello);
	string temp;
	string temp2;
	if (ss >> temp) { //takes the first user input
		if (ss >> temp2) {//takes the second user input
			auto temp3 = filesys->openFile(temp); // checks if the old file is a nullptr
			if (temp3 == nullptr) {
				
				return 1;
			}
			auto temp4 = temp3->clone(temp2, temp3); //The first file is then used to clone itself, and create a new file
			int r = filesys->addFile(temp4->getName(), temp4); // the newly created copy is added to the filesystem
			filesys->closeFile(temp3);
			return r; //returns the success or failure of the adding to the file system
		}
	}
	else {
		return 1;
	}
	return 1; // if the user input is incorrect, the command will fail and return 1
}

void CopyCommand::displayInfo()
{
}
