// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include "textfile.h"
#include "imagefile.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* a)
{
	string temp1 = a->getName();
	cout << temp1;
	for (unsigned int i = 0; i < (20 - temp1.size()); ++i) {
		cout << " ";
	}
	cout << "text";
	cout << "                ";
	cout << a->getSize();
	cout << endl;

}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* a)
{
	string temp1 = a->getName();
	cout << temp1;
	for (unsigned int i = 0; i < (20 - temp1.size()); ++i) {
		cout << " ";
	}
	cout << "image";
	cout << "               ";
	cout << a->getSize();
	cout << endl;
}
