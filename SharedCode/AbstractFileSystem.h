#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
#include <set>

class AbstractFileSystem {
private:

public:
	virtual int addFile(std::string filename, AbstractFile* newfile) = 0;
	virtual int deleteFile(std::string filename) = 0;
	virtual AbstractFile* openFile(std::string filename) = 0;
	virtual int closeFile(AbstractFile* newfile) = 0;
	virtual set<string> getFileNames() = 0;
	virtual set<std::string> getFileData() = 0;
};