#include "PasswordProxy.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* a, std::string b) : filePointer(a), password(b){
	
}

PasswordProxy::~PasswordProxy()
{
	delete filePointer;
}

std::string PasswordProxy::passwordPrompt()
{
	cout << "Please enter your password: " << endl;
	cout << endl;
	string input;
	cin >> input;


	return input;

	
}

vector<char> PasswordProxy::read()
{
	string userPass = passwordPrompt();
	if (userPass != password)
		return vector<char>();

	return filePointer->read();
	
}

int PasswordProxy::write(vector<char> contents)
{

	string userPass = passwordPrompt();
	if (userPass != password)
		return 1;

	return filePointer->write(contents);
}

int PasswordProxy::append(vector<char> contents)
{

	string userPass = passwordPrompt();
	if (userPass != password)
		return 1;

	return filePointer->append(contents);
}

unsigned int PasswordProxy::getSize()
{
	

	return filePointer->getSize();
}

string PasswordProxy::getName()
{
	return filePointer->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* a)
{
	string userPass = passwordPrompt();
	if (userPass != password)
		return; // check this

	filePointer->accept(a);
}

PasswordProxy* PasswordProxy::clone(std::string s, AbstractFile* original)
{
	AbstractFile* afile = filePointer->clone(s, original);
	PasswordProxy* newpp = new PasswordProxy(afile, this->password);
	return newpp;
}
