#pragma once
// declaration of MetadataDisplayVisitor here
class AbstractFile;
#include "AbstractFileVisitor.h"
#include <string>


class MetadataDisplayVisitor : public AbstractFileVisitor{
private:
	std::string name;
	int size;
	AbstractFile* type;
public:
	void visit_TextFile(TextFile* a);
	void visit_ImageFile(ImageFile* a);

};