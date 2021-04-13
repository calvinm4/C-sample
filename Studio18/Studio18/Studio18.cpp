// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileFactory.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\TextFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFile.h"
class AbstractFileFactory;
class AbstractFile;
using namespace std;
#include <iostream>
#include <vector>

int main()
{
	AbstractFileSystem* hello = new SimpleFileSystem();
	AbstractFileFactory* goodbye = new SimpleFileFactory();
	AbstractFile* temp = goodbye->createFile("a.txt");

	vector<char> abc = { 'a','b','c' };

	temp->getName();
	temp->getSize();
	temp->write(abc);
	temp->read();
	
	
	
	return 0;
}
