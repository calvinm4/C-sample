// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileFactory.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\TextFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\BasicDisplayVisitor.h"

class AbstractFileFactory;
class AbstractFile;
using namespace std;
#include <iostream>
#include <vector>

int main()
{
	std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	ImageFile e("name");

	e.write(v);
	//cout << e->read()[4];

	AbstractFileVisitor* temp = new BasicDisplayVisitor;

	e.accept(temp);
	
}