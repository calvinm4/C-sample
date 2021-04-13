studio 18 answers here
1. Mason Rocha, Jasper Wilson, Calvin Mitchell
2. We think implementing a new file system would be difficult. We would need to modify the file type code and the file system code. We have to check every single file type to implement our current design, which is difficult to change when adding new file types.
3. Easier to add enw file types when you are changing functionality. You can have a bunch of different file systems to inherit from the file factory, which makes us program less code and reuse it. 
   We want to create a new file factory class when we have a new file type we are using, such as if you didnt want to allow some.
   We need to modify createFile only.
   Yes, it can implement multiple files.
   It could create two files, but they should already be created.

4. AbstractFileSystem* hello = new SimpleFileSystem();
	AbstractFileFactory* goodbye = new SimpleFileFactory();
	AbstractFile* temp = goodbye->createFile("a.txt");

	vector<char> abc = { 'a','b','c' };

	temp->getName();
	temp->getSize();
	temp->write(abc);
	temp->read();
	
	output : a.txt0abc

5. Just the abstract file system
6.