studio 19 answers here
1. Mason Rocha, Jasper Wilson, Calvin Mitchell
2. here were the tests that we ran:
	AbstractFile* a = new TextFile("name");
	vector<char> c = { 'a','b','c' };
	a->write(c);

	for (char b : a->read())
		cout << b;
	vector<char> d = { 'a','b','c' };
	a->write(d);

	for (char b : a->read())
		cout << b;
 3. The sequence of communication is a visitor takes a file type of its own type, the object accepts this, and calls the visitor function that lets the class see it. 
 4. It makes a new class to do all of these fuction instead of having each function make their own unique version of visit. Different visitor types can read files in different ways, without having to check the other files.
 5. MetadataDisplay would have to be updated every new object, as would simple file factory. This creates a bunch of spaghetti code as you try to create dozens of new file types that all need visitors and each is different from the other. In other words, this is very messy to code.
