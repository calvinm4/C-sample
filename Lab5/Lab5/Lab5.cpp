// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*#include "..\..\SharedCode\AbstractFileFactory.h"
#include "..\..\SharedCode\AbstractFileSystem.h"
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\TouchCommand.h"
#include "..\..\SharedCode\LSCommand.h"
#include "..\..\SharedCode\" */

#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/CommandTest.h"
#include "../../SharedCode\LSCommand.h"
#include "../../SharedCode\RemoveCommand.h"
#include "../../SharedCode\CatCommand.h"
#include "../../SharedCode\DisplayCommand.h"
#include "../../SharedCode\CopyCommand.h"
#include "../../SharedCode\MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	// SET UP FILE SYSTEM
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();  //instructor code
	// CREATE COMMAND
	TouchCommand* tc = new TouchCommand(sfs, sff);

	std::string hello;
	std::string line;

	

	AbstractCommand* ls = new LSCommand(sfs); //creation of all the command objects
	AbstractCommand* rm = new RemoveCommand(sfs);
	AbstractCommand* cat = new CatCommand(sfs);
	AbstractCommand* ds = new DisplayCommand(sfs);
	AbstractCommand* cp = new CopyCommand(sfs);
	MacroCommand* rn = new MacroCommand(sfs); //creation of the macrocommand for remove
	AbstractParsingStrategy* strat = new RenameParsingStrategy(); //parsing strategy.
	rn->setParseStrategy(strat); //adding the commands to the macro remove
	rn->addCommand(cp);
	rn->addCommand(rm);
	

	while (1) { //while loop that goes in detecting the users first input to see what command the command line should execute.
		cout << endl;
		cout << "Please enter your command." << endl;
		cin >> hello;
		getline(cin, line); //gets the rest of the users input and pushes it into the command that will be executed.
		line.erase(0, 1);

		if (hello == "ls") { //checks if ls and executes the ls command if so
			if(ls->execute(line) != 0)
				cout << "Usage: ls" << endl; //if command failed
		}
		else if (hello == "rm") { //checks if ls and executes the ls command if so
			if(rm->execute(line) != 0)
				cout << "Usage: rm <filename>" << endl; //if command failed
		}
		else if (hello == "rn") { //checks if rn and executes the rn command if so
			if (rn->execute(line) != 0)
				cout << "Usage: rn <filename> <newfilename>" << endl; //if command failed
		}
		else if (hello == "cat") {	//checks if cat and executes the cat command if so
			if(cat->execute(line) != 0)
				cout << "Usage: cat <filename> [-a]" << endl; //if command failed
		}
		else if (hello == "ds") { //checks if ds and executes the ds command if so
			if(ds->execute(line) != 0)
				cout << "Usage: ds <filename> [-d]" << endl; //if command failed
		}
		else if (hello == "cp") { //checks if cp and executes the cp command if so
			if(cp->execute(line) != 0)
				cout << "Usage: cp <filename> <newfilename>" << endl; //if command failed
		}
		else if (hello == "touch") { //checks if touch and executes the touch command if so
			if(tc->execute(line) != 0)
				cout << "Usage: touch <filename>" << endl; //if command failed
		}
		else { //if the user did not input a valid command, print this message and continue the loop
			cout << "This command is invalid, enter either ls, rm, cat, ds, cp, or touch." << endl;
			
		}
}

	

	return 0;
}


