// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main()
{

	AbstractFile* text = new TextFile("name");
	vector<char> chars = { 'a','b','c','d','1','2' };
	
	text->getSize();
	text->getName();
	text->write(chars);
	text->append(chars);
	text->read();
}


