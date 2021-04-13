#include "BasicDisplayVisitor.h"
#include <iostream>
#include "ImageFile.h"
#include <vector>
#include "TextFile.h"
using namespace std;
// definitions of basic display visitor here

void BasicDisplayVisitor::visit_TextFile(TextFile* a)
{
	vector<char> contents = a->read();
	for (char a : contents)
		cout << a;

}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* a)
{
	
	
	vector<char> contents = a->read();
	
	if (contents.size() == 0) {		
		return;
	}
	
	int size = (int)sqrt(contents.size());
	

for (int j = size - 1; j > - 1 ; --j ) { 

	for (int i = 0; i < size ; ++i) {			// printing out image file according to instructions
	
		int temp = (size) * j + i;

		cout << contents[temp]; 

	}
	cout << endl;
}


}
