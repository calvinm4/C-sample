#include "TouchCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

TouchCommand::TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b): filesys(a), filefac(b)
{
}

int TouchCommand::execute(std::string hello) //used to create and add a file to the system
{
	istringstream ss(hello);
	string temp;
	string temp2;
	if (ss >> temp) { //gets the first input
		if (ss >> temp2) { //gets the second input
			if (temp2 == "-p") { //if -p, then create a password proxy to add  to the file system
				cout << "What is your password?" << endl;
				cout << endl;
				string input; //prompt user for password
				cin >> input;
				auto j = filefac->createFile(temp);
				PasswordProxy* c = new PasswordProxy(j, input); //creates password
				int succesful = filesys->addFile(temp, c); //adds it to the system
				if (succesful == 0) { //checks if the file was created successfully or not
					return 0;
				}
				else {
					delete c;
					return 1;
				}
			}
		} //otherwise, create a new file with the name entered
		auto j = filefac->createFile(temp); //creates file
		int succesful = filesys->addFile(temp, j); //adds file
		if (succesful == 0) {
			return 0;
		}
		else { //deletes newly created file if invalid
			delete j;
			return 1;
		}
	}
	return 1;
}

void TouchCommand::displayInfo()
{
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}
