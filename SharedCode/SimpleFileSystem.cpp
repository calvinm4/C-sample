// define methods of SimpleFileSystem class here

#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <memory>

using namespace std;

 int SimpleFileSystem::addFile(std::string filename, AbstractFile* newfile) {
	 std::map<string, AbstractFile*>::iterator iter;

	
	 
	 if (maps.find(filename) == maps.end())
	 {
		 if (newfile != nullptr) {
			 maps.insert({ filename, newfile });
			 return 0;
		 }
		 else
			
			 return 1;
	 }
	 else
		 
		 return 1;

	 return 0;

}

 

 int SimpleFileSystem::deleteFile(std::string filename) {
	 if (maps.find(filename) == maps.end())
		 return 4;
	 if (sets.find(maps[filename]) != sets.end())
		 return 5;
	 
	 
	 delete maps[filename];
	 
	 maps.erase(filename);


	 return 0;
 }

 AbstractFile* SimpleFileSystem::openFile(std::string filename) {
	 if (maps.find(filename) == maps.end())
		 return nullptr;
	 else if (sets.find(maps[filename]) != sets.end())
		 return nullptr;

	 sets.insert(maps[filename]);

	 return maps[filename];

}

 int SimpleFileSystem::closeFile(AbstractFile* newfile) {
	 if (!(sets.find(newfile) == sets.end()))
		 sets.erase(newfile);
	 else
		 return 2;

	 return 0;
}

 std::set<std::string> SimpleFileSystem::getFileNames() // this function prints out all of the names of files in the set.
 {
	 std::set<std::string> outPut;
	 int lineCt = 0;
	 int constTemp = 2;
	 for (auto j : maps) { // prints out everything in maps
		 lineCt += 1;
		 outPut.insert(j.first); //just the name, which is the first item in the set.
		 cout << j.first;
		 for (unsigned int i = 0; i < 20 - j.first.size(); ++i) {
			 cout << " ";
		 }
		 if ((lineCt % constTemp) == 0) {
			 cout << endl;
		 }

	 }
	 return outPut;
 }

 std::set<std::string> SimpleFileSystem::getFileData() //prints out the file names and then the metadata.
 {
	 std::set<std::string> outPut;
	 for (auto j : maps) { // for each item in the map, visit the file and return its data
		 outPut.insert(j.first);
		 AbstractFileVisitor* temp = new MetadataDisplayVisitor;
		 j.second->accept(temp); //visits the file and returns the name and data.

	 }
	 return outPut; //returns the set with data
 }
