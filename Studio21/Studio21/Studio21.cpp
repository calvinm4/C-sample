// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\TouchCommand.h"
#include "H:\Labs\Lab5\oop_work-mason_jasper_calvin\SharedCode\CommandPrompt.h"

int main()
{
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	TouchCommand* tc = new TouchCommand(sfs, sff);
	CommandPrompt* cp = new CommandPrompt();
	cp->setFileFactory(sff);
	cp->setFileSystem(sfs);
	cp->addCommand("touch", tc);
	cp->run();

}

