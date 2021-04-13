#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
// studio 18 - simple file factory definitions

AbstractFile* SimpleFileFactory::createFile(std::string filename)
{

	string extensionName;
	for (unsigned int i = 0; i < filename.size(); i++) {
		if (filename[i] == '.') {
			for (unsigned int j = i + 1; j < filename.size(); j++)
				extensionName += filename[j];
		}

	}

	if (extensionName == "txt") {
		AbstractFile* newfiletext = new TextFile(filename);
		if (newfiletext != nullptr) {
			return newfiletext;
		}
		else
			return nullptr;
	}
		

	else if (extensionName == "img") {
		AbstractFile* newfileimg = new ImageFile(filename);
		
		if (newfileimg != nullptr) 
			return newfileimg;
		else
			return nullptr;
	}

	else

		return nullptr;

}
