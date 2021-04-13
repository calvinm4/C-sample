#pragma once
#include <string>
#include <vector>
#include "AbstractFile.h"
// Image file class declaration here

class ImageFile : public AbstractFile {
private:
	vector<char> contents;
	std::string name;
	char size;
public:
	ImageFile(std::string name);
	unsigned int getSize();
	vector<char> read();
	int write(vector<char> newContents);
	int append(vector<char> newContents);
	std::string getName();
	void accept(AbstractFileVisitor* a);
	~ImageFile();
	ImageFile* clone(string s, AbstractFile* original);
};