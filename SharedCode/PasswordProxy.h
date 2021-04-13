#pragma once
#include <string>
#include "AbstractFile.h"
#include <vector>


class PasswordProxy: public AbstractFile {
private:
	AbstractFile* filePointer;
	std::string password;

	

public:
	PasswordProxy(AbstractFile* a, std::string b);
	~PasswordProxy();
	std::string passwordPrompt();

	vector<char> read();
	int write(vector<char> contents) ;
	int append(vector<char> contents) ;
	unsigned int getSize() ;
	string getName() ;
	void accept(AbstractFileVisitor* a) ;
	PasswordProxy* clone(std::string s, AbstractFile* original);


};