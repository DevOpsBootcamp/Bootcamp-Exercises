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
* rmdir
* grep
* apropos

Where to ask questions:
-----------------------
If you are on irc, don't be shy about asking in #osu-lug!  

You can also type `man <command>` and a manual page will tell you
what the command does.


cd
--

First thing's first: open up a terminal and run

```sh
$ cd
```

cd means change directory.  This will make sure that you're in your 
home (~) directory.  You can always
run `cd` without any arguments to be taken back to your home directory!

ls
--

Next, type

```sh
$ ls
```

ls means list the files in the directory.  You can also do `ls -a` to show
dot files, and `ls -l` to get more information about the files in your 
directory.

You can use cd and ls to traverse a file system and know where you are.  
See if you can list all the files in your root directory (/), and the 
date they were last edited.

touch
-----

You can create empty files using the `touch` command.

```sh
$ touch testing.txt
```

You can name the file whatever you'd like; testing is just an example.

Note: `touch` will create a file for each argument you pass it, so

```sh
$ touch file1 file2
```

will create two files, _not_ one file named `file1 file2`. If you really
want a file whose name has a space in it, put it in quotes:

```sh
$ touch 'file 1' # creates one file
```

Alternatively, you can open a file with your favorite text editor, and
then just save it to create the file. 

mv
--
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

mkdir
-----

Now, to create a directory, we use the `mkdir` command.

```sh
$ mkdir Bootcamp
```

Again, you can name it whatever you'd like, so long as it doesn't have
spaces.  

Now, trying moving the file you created into your new directory

cat
---

To concatenate files and print them to your terminal, use `cat`

```sh
$ cat <myawesomefile>
```


pwd
---

To print the path of the directory you're currently in, us `pwd` (means
print working directory)

```sh
$ pwd
```

Try printing your current directory, changing directories, and printing again.

rm
--

To remove files or directories use `rm`

```sh
$ rm <myawesomefile>
```

The best way to remove a directory is to use rm's cousin, `rmdir`:

```sh
$ rmdir <directory
```

At this point you should make a directory that contains a few files
and watch what happens when you try do remove it with `rmdir`:

```sh
$ mkdir rmdir_test
$ touch rmdir_test/file1 rmdir_test/file2
$ rmdir rmdir_test
# How does the behavior of rmdir change?
```

You can also use `rm -i` to make rm ask before deleting each file.

grep
----

To search through a file or directory for a string, use `grep`

```sh
$ grep <string you're looking for> <file or directory you're looking in>
```

By default `grep` only looks at the files in the directory you pass it --
it does _not_ look in directories. If you want it to look at everything,
you need to pass it `-r` for recursive. A common idiom is to combine this
with `-i` (case insensitive searching).

```sh 
$ grep -ir <string you're looking for> <directory you're looking in>
```

apropos
-------

The `apropos` command searches manpages for the keywords you pass as arguments.
It prints out a list of man pages and a short description for each page that
matches the keyword(s). For example:

```sh
$ apropos apropos
apropos(1), whatis(1)   - keyword search whatis documentation databases
```

Some keywords will return an awful lot of manpages.

Note: `apropos` does a search for each argument individually. This means
that:

```sh
$ apropos apropos builtin
```

Will return more entries than `apropos apropos` or `apropos builtin` alone!

---

Congratulations!  You've finished the basic bash exercises.  If you've
still got some time, head over to the steam-locomotive document
to really test your bash knowledge.
