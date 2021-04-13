#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>
#include "MetadataDisplayVisitor.h"

class SimpleFileSystem: public AbstractFileSystem {
protected:
	std::map<std::string, AbstractFile*> maps;
	std::set<AbstractFile*> sets;
public:
	int addFile(std::string filename, AbstractFile* newfile);
	int deleteFile(std::string filename);
	AbstractFile* openFile(std::string filename);
	int closeFile(AbstractFile* newfile);
	std::set<std::string> getFileNames();
	std::set<std::string> getFileData();

};