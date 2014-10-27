Steam Locamotive
================
Do this if you know about the following:
* Basic file commands like `mv`, `cp`, etc.
* What `.`, `..`, and `~` mean
* How to pass a command options and arguments
* What a man page is
* How to use `nano` or `vim`
* Are somewhat familar with `git`

When you are typing you often make typos. It is easy to flip the letters in
`ls` and type `sl` by accident. There is a charming program called `sl` to
break you of this habit. Running `sl` shows a steam locamotive zipping accross
your terminal. We are going to download and compile `sl`.

First, visit the github repository in your browser:
https://github.com/mtoyoda/sl
Poke around. If you are curious, can you figure out how the smoke is animated?


Next, use git to clone, or make a copy of the repository on your vm.
```sh
$ git clone https://github.com/mtoyoda/sl
```

Next we need to use `cd` to enter the directory with the code you just 
downloaded. For a gold star, can you figure out when the `sl.c` file was
last modified? Use `ls` and an option.

Next, compile the program using make.
```sh
$ make
```
Make runs a series of commands to compile a program. If your program is very
large and there is a lot of code you can optionally include having a good 
Makefile is important.
Can you tell what command `make` ran? What options did the command use, and
what do the options do? (Hint: `man gcc`).
Open up the Makefile. What is the value of the `CC` variable?  

Next, if you look at the current directory, there is a new file called `sl`.
This is the program you just compiled. To learn a little more about this file,
open it up in your file editor, `nano`.

```sh
$ nano sl
```

You should see a bunch of garbage. That is because this is a compiled
executable. To learn more about the `sl` file, use the handy `file` command:

```sh
$ file sl
```

This will tell you that it is a 64-bit executable compiled for your operating
system and hardware.

Now, actually run the file:

```sh
$ ./sl
```
The `./` at the beginning is the path to the file. Remember, `.` is the current
directory, and `/` is the separator between files and directories.
If you go to another directory (try `cd ~`), how can you run `sl`?

In order to execute a file, you need the right permissions. Run `ls -l`


`sl` is a command just like any other command. For example, take a look at
`echo`. 

```sh
$ echo hello world
```

Where is the echo program? To find out, run:
```sh
$ which echo
```
If you want you can also find other programs and data files related to echo
by running:
```sh
$ whereis echo
```
You may see a file like `/usr/share/man/man1/echo.1.gz` displayed. This is the
man page for `echo`. When you type `man echo` you display that file.
Take a peak at what is in that file with nano. You should see more garbage.
Run the `file` command to figure out what that file really is.

To learn more about gzipped files, run `man gzip`. `gzip` is a program which
zips and unzips `*.gz` files. Use `gunzip` to unzip that man page so we can
read it.
```sh
$ gunzip /usr/share/man/man1/echo.1.gz
```
You probably got an error like `Permission denied`. That's because when you run
`gunzip`, it tries to create a file called `echo.1` in `/usr/share/man/man1/`,
but you don't have permission to write a new file there. Let's copy the
`echo.1.gz` file to your current directory.
```sh
$ cp /usr/share/man/man1/echo.1.gz . # remember . is the current directory
```
Now try unzipping the file you just copied:

```sh
$ gunzip /usr/share/man/man1/echo.1.gz
```
You should get a file like `echo.1`. Try opening it with `nano`. It still looks
kind of funny, but now you can read parts of the man page. That's because `man`
reads compressed `echo.1.gz`, uncompresses it, and then formats it specially
according to the formatting symbols and displays it.
Try moving the uncompressed `echo.1` file back to `/usr/share/man/man1/`.
Again, you should get `Permission denied`.
To learn what permissions you  have for that file, run:
```sh
$ ls -l /usr/share/man/man1/echo1=,1,gz
```
The `-l` option stands for `long listing`.
This should display the following:
```
-rw-r--r-- 1 root root 1151 Jan 26  2013 /usr/share/man/man1/echo.1.gz
```
The columns are:
* File permissions
* Number of links
* The file's owner
* The owner's group
* The file size in bytes
* The date the file was created
* The full path to the file

Not all of these will make sense right now, but now you know how to find them
when you need them later.
The permissions are arranged in an interesting manner. They are grouped into
three parts, owner, group, and everyone else.
```
rw-   | r--   | r--
owner | group | everyone else
```
The `r` stands for read, `w` stands for `write` and `x` stands for execute.
You can see that the file `/usr/share/man/man1/echo.1.gz` is readable and
writable by the root user, readable by root's group (also named root), and
just readable by everyone else. If you run `ls -l` on `/usr/share/man/` you can
see that you don't have permissions to write to the `man1` directory, which is
why you couldn't unzip the `echo.1.gz` file in that directory. If you are sharp
eyed, you'll notice that directory permissions begin with a `d` and file
permissions just begin with a `-`.
Let's look at the permissions for `sl`. You can see that your user owns the
file and has `rwx` permissions. We can change these permissions by using the
`chmod` command. If we want to remove the execute permission, just do:
```sh
$ chmod -x sl
```
What happens when you try and execute it?
You can add the permissions back by doing:
```sh
$ chmod +x sl
```
Can you guess how to remove and add read and write permissions?
Obviously you can only change permissions for files you own, unless you become
another user.
There's one last sticker. You can't run the `sl` program from anywhere in the
system. To do that, we need to learn how your shell finds programs which it
can execute anywhere. It uses the environment variable called `$PATH`. An
environment variable holds some value that programs can read and write.
You can view the value of an environment variable by running:
```sh
$ echo $PATH
```
You can see what shell you're using by looking at `$SHELL`.
You can set some environment variable by doing:
```sh
$ SOMEVAR="some string" # notice there is no $ before SOMEVAR!
```
You'll see a bunch of directories separated by `:` characters. These are the
directories your shell searches to find commands. To be able to use the `sl`
command from anywhere, we need to put it in one of these directories. Typically
binary files go in `/bin`, which stands for binaries. Let's try moving `sl`
there:

```sh
$ mv sl /bin
```
Permissions again. Let's see who owns `/bin`. It looks like root is the owner.
It turns out there is a command to run a command as root called `sudo`.
`sudo` stands for super-user-do, since root is the super user. It executes
whatever command comes afterwards as root.
```sh
$ sudo mv sl /bin
```
Now you can run sl from anywhere without typing the full path.
