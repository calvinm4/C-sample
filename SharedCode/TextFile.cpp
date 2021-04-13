#include "TextFile.h"
#include "AbstractFileVisitor.h"
using namespace std;
#include <iostream>

//  Define the TextFile class here

TextFile::TextFile(string n) {
	name = n;

}


unsigned int TextFile::getSize() {
	return contents.size();

}

string TextFile::getName() {
	
	return name;

}

void TextFile::accept(AbstractFileVisitor* a)
{
	a->visit_TextFile(this); // visitor visits file using whatever its visit function is
}


TextFile::~TextFile()
{
	
}

TextFile* TextFile::clone(string s, AbstractFile* original) //clone function that will copy the textfile and its content
{
	TextFile* textfl = new TextFile(s+".txt"); //creates the new textfile
	textfl->write(contents); //copy the contents of the original into the new
	return textfl; //return the new textfile
}

int TextFile::write(vector<char> newContents) {
	contents = newContents;

	return 0;

}

int TextFile::append(vector<char> newContents) {
	for (unsigned int i = 0; i < newContents.size(); i++)
		contents.push_back(newContents[i]);

	return 0;
}

vector<char> TextFile::read() {

	return contents;

}

