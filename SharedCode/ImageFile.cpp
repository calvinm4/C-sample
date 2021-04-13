// definition of ImageFile class here
#include "ImageFile.h"
#include <string>
#include <iostream>
#include "AbstractFileVisitor.h"
using namespace std;

ImageFile::ImageFile(string n){
	name = n;
	size = 0;
	contents = {};
}

unsigned int ImageFile::getSize() {
	
	return contents.size();

}

string ImageFile::getName() {
	
	return name;

}

void ImageFile::accept(AbstractFileVisitor* a)
{
	a->visit_ImageFile(this);	// file visited using visitor's visit function
}

ImageFile::~ImageFile()
{
	
}

int ImageFile::write(vector<char> newContents) {

if (newContents.size() == 0)
		return 1; 

	
	int xs = 0;
	for (unsigned int i = 0; i < newContents.size() - 1; i++) {
		if (newContents[i] == 'X')
			xs++;
		if (newContents[i] == ' ')									//checking that input is well formed
			xs++;
		if (newContents[i] != 'X' && newContents[i] != ' ') {
			return 1;
		}
	}
	
	if ((newContents[newContents.size() - 1] - 48)  != sqrt(xs))
		return 1;
		
	if (newContents[newContents.size()-1] - 48 < 0 || newContents[newContents.size()-1] - 48 > 9) {
		return 1; 
	}
	
	for (unsigned int i = 0; i < newContents.size() - 1; ++i) {
		contents.push_back(newContents[i]);
	}
	
	size = newContents[contents.size()] - 48;	// set size to number at end of input

	
	return 0;

}

int ImageFile::append(vector<char> newContents) {
	return 3;
}

 vector<char> ImageFile::read() {
	 
	

	 return contents;
}

 ImageFile* ImageFile::clone(string s, AbstractFile* original) // this method clones the file inputed, and copys the data inside the old file into the new one.
 {
	 auto temp3 = original->getSize();
	 ImageFile* imgfl = new ImageFile(s + ".img"); //creates the new file
	 vector<char> con = contents;
	 con.push_back(this->size + 48); // adding the contents of the old file into new
	 imgfl->write(con);
	 
	
	 return imgfl; //returns the newcloned file
 }