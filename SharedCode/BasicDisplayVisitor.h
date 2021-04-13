#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
class TextFile;
class ImageFile;

class BasicDisplayVisitor: public AbstractFileVisitor {

public:
	void visit_TextFile(TextFile* a) ;
	void visit_ImageFile(ImageFile* a) ;





};