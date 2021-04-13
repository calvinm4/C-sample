Calvin Mitchell 466136, Mason Rocha 475683, Jasper Wilson 465713

Work was all done together in zoom so everyone contributed to every part.

Errors and warnings: We had to deal with a lot of warnings having to do with using signed instead of unsigned integers and making sure all control paths returned a value. The only big error that we had was we didn't always close files after using them, leading to errors when commands were used in succession.

Testing:

C:\Users\calvin.mitchell\source\repos\cse332s-fl20-wustl\oop_work-mason_jasper_calvin\Lab5\Debug>Lab5.exe

Please enter your command.
touch file.txt

Please enter your command.			// two initial files added
touch image.img

Please enter your command.			// all different potential cat commands on a text file
cat file.txt
What do you want to write to the file? :q to exit without saving, :wq to save and exit
test text input with saving
:wq

Please enter your command.
ds file.txt
test text input with saving
Please enter your command.
cat file.txt -a
What do you want to append? :q to exit without saving, :wq to save and exit
test text input with saving
appending
:wq

Please enter your command.
ds file.txt
test text input with savingappending
Please enter your command.
cat file.txt
What do you want to write to the file? :q to exit without saving, :wq to save and exit
overwriting
:wq

Please enter your command.
ds file.txt
overwriting
Please enter your command.
cat file.txt
What do you want to write to the file? :q to exit without saving, :wq to save and exit
exit without saving
:q

Please enter your command.
ds file.txt
overwriting
Please enter your command.					// cat command on image type
cat image.img
What do you want to write to the file? :q to exit without saving, :wq to save and exit
X X X X X3
:wq

Please enter your command.					// both ways to display img files
ds image.img
X X
 X
X X

Please enter your command.
ds image.img -d
X X X X X

Please enter your command.
ls -m
file.txt            text                11				// metadata working correctly
image.img           image               9

Please enter your command.								// copy adding to file system and checking display + metadata
cp file.txt copy

Please enter your command.
ls
copy.txt            file.txt
image.img
Please enter your command.
ls -m
copy.txt            text                11
file.txt            text                11
image.img           image               9

Please enter your command.
ds copy.txt
overwriting
Please enter your command.
ds file.txt
overwriting
Please enter your command.
cp image.img copy										// img files copy correctly

Please enter your command.
ls
copy.img            copy.txt
file.txt            image.img

Please enter your command.
ls -m
copy.img            image               9
copy.txt            text                11
file.txt            text                11
image.img           image               9

Please enter your command.
ds copy.img
X X
 X
X X

Please enter your command.
ds image.img
X X
 X
X X

Please enter your command.							// renaming img file
rn copy.img renamed

Please enter your command.
ls
copy.txt            file.txt						// old file name no longer present
image.img           renamed.img

Please enter your command.
ds renamed.img										// renamed file has expected contents
X X
 X
X X

Please enter your command.
rn file.txt rn										// renaming for text

Please enter your command.
ls
copy.txt            image.img
renamed.img         rn.txt

Please enter your command.
ds rn.txt
overwriting
Please enter your command.
rm image.img											// remove deletes from file system as expected

Please enter your command.
ls
copy.txt            renamed.img
rn.txt
Please enter your command.
touch pass.txt -p											// password protected file
What is your password?

pswrd

Please enter your command.								
ls
copy.txt            pass.txt
renamed.img         rn.txt

Please enter your command.
ds pass.txt
Please enter your password:

pswrd

Please enter your command.
cat pass.txt
What do you want to write to the file? :q to exit without saving, :wq to save and exit
dhwbdh
:wq
Please enter your password:

pswrd

Please enter your command.
ds pass.txt
Please enter your password:

pswrd
dhwbdh
Please enter your command.
ls
copy.txt            pass.txt
renamed.img         rn.txt

Please enter your command.						// checking removing text file
rm copy.txt

Please enter your command.
ls
pass.txt            renamed.img
rn.txt
Please enter your command.


// all of these tests ran as expected