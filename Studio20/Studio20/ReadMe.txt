1. Mason Rocha, Jasper Wilson, Calvin Mitchell
2. We do not want to have a memory link. Also, since we are using passwords, if the memory gets leaked, someone could end up stealing the password.
4. 	Test:
	AbstractFile* a = new TextFile("name");
	string password = "password";
	AbstractFileVisitor* d = new BasicDisplayVisitor;
	vector<char> c = { 'X',' ', 'X',' ' , 'X',' ' , 'X',' ' , 'X' , '3' };

	PasswordProxy* b = new PasswordProxy(a,password);
	
	b->write(c);
	b->append(c);
	b->accept(d);
	b->read();
	b->accept(d);

	Results:

H:\Labs\Lab5\oop_work-mason_jasper_calvin\Studio20\x64\Debug>studio20.exe
Please enter your password:

password
Please enter your password:

password
Please enter your password:

password
X X X X X3X X X X X3Please enter your password:

password

H:\Labs\Lab5\oop_work-mason_jasper_calvin\Studio20\x64\Debug>studio20.exe
Please enter your password:

password
Please enter your password:

a
Please enter your password:

a
Please enter your password:

a
Please enter your password:

a

5. 