// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileSystem.h"
using namespace std;


int main()
{
	SimpleFileSystem sfs;
	ImageFile* img = new ImageFile("FileName.img");
	sfs.addFile(img->getName(), img);
	
	sfs.deleteFile(img->getName());


}

