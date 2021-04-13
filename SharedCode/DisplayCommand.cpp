#include "DisplayCommand.h"
#include "RemoveCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

DisplayCommand::DisplayCommand(AbstractFileSystem* a) : filesys(a)
{
}

int DisplayCommand::execute(std::string hello) //this command will display the characters stored in each text or image file, and if it is an image file it will format it if the user types -d
{
	istringstream ss(hello);
	string temp;
	string temp2;
	if (ss >> temp) { //gets the first user input value
		if (ss >> temp2) { //gets the second user input value
			if (temp2 == "-d") { //if the second value is -d, then format the file (images0
				auto temp3 = filesys->openFile(temp);
				if (temp3 == nullptr) {
					return 1;
				}
				auto temp4 = temp3->read();
				for (auto temp5 : temp4) { //prints out file formatted.
					cout << temp5;
				}
				cout << endl;
				filesys->closeFile(temp3); //closes file
				return 0;
			}
		}
		else {
			AbstractFileVisitor* dspv = new BasicDisplayVisitor; //creates a visitor to go get the files data and return it
			auto temp3 = filesys->openFile(temp);
			
			if (temp3 == nullptr) {
				return 2;
			}
			temp3->accept(dspv); //visits file and prints it out
			filesys->closeFile(temp3); //closes the file
			return 0;
		}
	}
	return 1; //returns 1 if the user input was incorrect and the command could not be executed.
}

void DisplayCommand::displayInfo()
{
	cout << "ds removes the filesystem. The command should be invoked with ds <filename> [-d]" << endl;

}
