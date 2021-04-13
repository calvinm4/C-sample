#pragma once
#include "AbstractFile.h"
#include <vector>
// TextFile declaration goes here

class TextFile: public AbstractFile {
private:
	string name;
	vector<char> contents;
protected:

public:
	TextFile(string name);
	unsigned int getSize();
	vector<char> read();
	int write(vector<char> newContents);
	int append(vector<char> newContents);
	string getName();
	void accept(AbstractFileVisitor* a);
	~TextFile();
	TextFile* clone(string s, AbstractFile* original);


};