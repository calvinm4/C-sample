#include "CommandPrompt.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>


CommandPrompt::CommandPrompt() 
{
	storageSystem = nullptr;
	storageFactory = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* a)
{
	storageSystem = a;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* a)
{
	storageFactory = a;
}

int CommandPrompt::addCommand(std::string a, AbstractCommand* b)
{

	if(stringToComm.insert(std::pair<std::string, AbstractCommand*> (a, b)).second)
		return 0;
	return 1;
}

int CommandPrompt::run()
{
	
	while (1) {
		string input = prompt();

		if (input == "q")
			return 1;
		if (input == "help") {
			listCommands();
		}
		


		if (input.find(' ') != string::npos) {
			istringstream ss(input);
			string temp;



			if (ss >> temp) { //check this
				string temp2;


					if (temp == "help") {
						ss >> temp2;
						auto b = stringToComm.find(temp2);
						if (b != stringToComm.end()) {
							b->second->displayInfo();
						}
						else {
							cout << "No such command";
						}


					}
					string temp3;
					while (ss >> temp2) {
						temp3 += temp2 + " ";
					}
					string temp4 = temp3.substr(0, temp3.size() - 1);
					auto b = stringToComm.find(temp);
					if (b != stringToComm.end()) {
						b->second->execute(temp4);
					}
					else {
						cout << "No such command";
					}

			}
		}

			else {
				auto b = stringToComm.find(input);
				if (b != stringToComm.end()) {
					b->second->execute("");
				}
				else {
					cout << "No such command";
				}

			}

		}
	}



void CommandPrompt::listCommands()
{
	for (const auto& p : stringToComm) {
		std::cout << p.first << std::endl; 
		
	}


}

std::string CommandPrompt::prompt()
{
	cout << "Please enter a command, 'q' to quit, 'help' for a lost of commands, or 'help <command name>' for details about a command: " << endl;
	cout << endl;
	cout << "$  ";
	string input;
	getline(cin, input);
	return input;
}
