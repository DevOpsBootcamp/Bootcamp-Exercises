Beginner Bash Exercises
=======================

If you are new to bash, or didn't go to DevOps Daycamp, here are some
basics to help get you familiarized with the bash shell.

* cd
* ls
* touch
* mv
* mkdir
* cat
* pwd
* rm
* grep

Where to ask questions:
-----------------------
If you are on irc, don't be shy about asking in #osu-lug!  

You can also type **man <command>** and a manual page will tell you
what the command does.

First thing's first: open up a terminal and run
```sh
$ cd
```
cd means change directory.  This will make sure that you're in your 
home (~) directory.  You can always
run **cd** without any arguments to be taken back to your home directory!

Next, type
```sh
$ ls
```

ls means list the files in the directory.  You can also do **ls -a** to show
dot files, and **ls -l** to get more information about the files in your 
directory.

You can use cd and ls to traverse a file system and know where you are.  
See if you can list all the files in your root directory (/), and the 
date they were last edited.

You can create empty files using the **touch** command.
```sh
$ touch testing.txt
```
You can name the file whatever you'd like **as long as it doesn't have spaces**, testing is just an example. 
Alternatively, you can open a file with your favorite text editor, and
then just save it to create the file. 

To rename a file or directory, or move it to a different directory, 
you use the mv command.  
```sh
$ mv testing.txt not-testing.txt
```
The first argument you pass it is the file you're moving, and the second
is where you're moving it to.  You can also move the same file to a 
new directory.
```sh
$ mv not-testing.txt ./Downloads/
```
Try creating a file named 'myfile.fileextension', moving it to a different
directory, and renaming it to 'mynewfile.filesyay'

Now, to create a directory, we use the **mkdir** command. 
```sh
$ mkdir Bootcamp
```
Again, you can name it whatever you'd like, so long as it doesn't have
spaces.  

Now, trying moving the file you created into your new directory

To concatenate files and print them to your terminal, use **cat**
```sh
$ cat <myawesomefile>
```

To print the path of the directory you're currently in, us **pwd** (means
print working directory)
```sh
$ pwd
```
Try printing your current directory, changing directories, and printing again.

To remove files or directories use **rm*
```sh
$ rm <myawesomefile>
```
Directories can be removed using the '-r' option.  Word to the wise: 
THINK BEFORE YOU RM.  And don't use -f. 

To search through a file or directory for a string, use **grep**
```sh
$ grep <string you're looking for> <file you're looking in>
```

```sh 
$ grep -r <string you're looking for> <directory you're looking in>
```

Congratulations!  You've finished the basic bash exercises.  If you've
still got some time, head over to the steam-locomotive document
to really test your bash knowledge.
