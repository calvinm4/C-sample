#pragma once
// studio 18 - file factory interface declared here
class AbstractFile;
class ImageFile;
class TextFile;
#include <string>

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string a) = 0;


};