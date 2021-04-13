#include "CatCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>


CatCommand::CatCommand(AbstractFileSystem* a) : filesys(a)
{
}

int CatCommand::execute(std::string hello) //this method either appends data to a file or replaces the data in a file, the user can save or quit
{
	istringstream ss(hello); //grab the string of user input
	string temp;
	string temp2;
	if (ss >> temp) { //get the first word
		if (ss >> temp2) { //second word
			if (temp2 == "-a") { // if the second is -a, initiate append
				auto temp3 = filesys->openFile(temp); //open the file and cehck if it is a nullptr
				if (temp3 == nullptr) {
					return 1;
				}
				auto temp4 = temp3->read();
				std::cout << "What do you want to append? :q to exit without saving, :wq to save and exit" << endl;
				for (auto temp5 : temp4) {
					std::cout << temp5; //print out its contents
				}
				std::cout << endl;
				
				vector<char> data;
				
				while (1) { //loop while the user inputs what they want into the file
					
					string input;
					getline(cin, input);
					if (input == ":q") //if user says :q, then quit
						return 0;
					if (input == ":wq") {//if user inputs :wq, then save and quit, otherwise the method will keep looping
						int r = temp3->append(data);
						filesys->closeFile(temp3);
						return r;
					}
					for (char k : input) { //push the data into the array of chars
						data.push_back(k);
					}
					

				}
			}
		}
		AbstractFile* temp3 = filesys->openFile(temp);
		if (temp3 == nullptr) {
			return 1;
		}
		// this is the case where the user does not input -a
		// it is almost identical to the previous lines excpet for not taking two strings out of the user input and checking them
		vector<char> data;
		std::cout << "What do you want to write to the file? :q to exit without saving, :wq to save and exit" << endl;
		while (1) {
			
			string input;
			getline(cin, input);
			if (input == ":q") { //quits and closes 
				filesys->closeFile(temp3);
				return 0;
			}
			if (input == ":wq") { //quits and saves, then closes
				data.pop_back();
				int r = temp3->write(data);
				filesys->closeFile(temp3);
				return r;
			}
			
			for (char k : input) {
				data.push_back(k);
			}
			data.push_back('\n');
		}
	}
	return 1; //if no command ran, then the input was invalid and the command fails.
}

void CatCommand::displayInfo()
{
	std::cout << "rm removes the filesystem. The command should be invoked with rm <filename>" << endl;
}
