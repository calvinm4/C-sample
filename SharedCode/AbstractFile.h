#pragma once
#include <vector>
#include <string>
#include <vector>

using namespace std;
class AbstractFileVisitor;

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFile {


public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> contents) = 0;
	virtual int append(vector<char> contents) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual void accept(AbstractFileVisitor* a) = 0;
	virtual AbstractFile* clone(string filename, AbstractFile* original) = 0;

};
