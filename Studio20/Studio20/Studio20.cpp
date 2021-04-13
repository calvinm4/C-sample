// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\PasswordProxy.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileFactory.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\SimpleFileSystem.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\ImageFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\TextFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\AbstractFile.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\BasicDisplayVisitor.h"
#define protected public
#undef protected

int main()
{
	AbstractFile* a = new TextFile("name");
	string password = "password";
	AbstractFileVisitor* d = new BasicDisplayVisitor;
	vector<char> c = { 'X',' ', 'X',' ' , 'X',' ' , 'X',' ' , 'X' , '3' };

	PasswordProxy* b = new PasswordProxy(a,password);
	
	b->write(c);
	b->append(c);
	b->accept(d);
	b->read();
	b->accept(d);

}

