#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"
#include <map>
#include <set>
class AbstractFile;


class SimpleFileFactory: public AbstractFileFactory {
protected:
	std::map<std::string, AbstractFile*> maps;
	std::set<AbstractFile*> sets;
public:
	AbstractFile* createFile(std::string filename);
	


};