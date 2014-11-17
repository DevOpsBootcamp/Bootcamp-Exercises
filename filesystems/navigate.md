Navigating Filesystems
======================

In this exercise you will create two files, `foo` and `bar`, and a directory
called `baz`.

These files will be owned by `root` because we are going to make them with
`sudo touch <file>` and `sudo <editor> <file>`. Sudo means you are running a 
single command as the `root` user.

`bar` should be created with your text editor and have a *secret* message
inside. Open the new file in vim and enter some unique text such as 'Devops
is so cool!' or 'I am learning about filestructuresi!'

```bash
[vagrant@devops-bootcamp ~]$ sudo touch foo
[vagrant@devops-bootcamp ~]$ sudo mkdir baz 
[vagrant@devops-bootcamp ~]$ sudo vim bar 
[vagrant@devops-bootcamp ~]$ ls -l
total 0
-rw-r--r--. 1 root root   25 Nov 15 00:23 bar
drw-r--r--. 1 root root 4096 Nov 15 00:23 baz
-rw-r--r--. 1 root root    0 Nov 15 00:23 foo
```

Now we want to edit one of these files, but because we are not the owner we are
not given permission to do so. To edit `bar` we need to run the `chown` command.

This command is structured `sudo chown $USER:$GROUP <file/dir>` and `sudo chown
-R $USER:$GROUP <directory>` to change the owner of directory's *and* all of
the directories contents.

```bash
[vagrant@devops-bootcamp ~]$ chown vagrant:vagrant bar
chown: changing ownership of `bar`: Operation not permitted 
[vagrant@devops-bootcamp ~]$ sudo chown vagrant:vagrant bar
[vagrant@devops-bootcamp ~]$ ls -l
total 4
-rw-r--r--. 1 vagrant vagrant   25 Nov 15 00:23 bar
drwxr-xr-x. 2 root    root    4096 Nov 15 00:35 baz
-rw-r--r--. 1 root    root       0 Nov 15 00:23 foo
```

Now that we own the file we can do anything with it, without having to run
`sudo`. We are going to change the permissions so everybody can read/write/
execute the file. The abstract command is `chmod <permissions> <file/dir>` and
`chmod -R <permissions> <directory>` to change the ownership of directories
*and* all of it the directory's contents.

```bash
[vagrant@devops-bootcamp ~]$ chmod 777 bar
[vagrant@devops-bootcamp ~]$ ls -l
total 4
-rwxrwxrwx. 1 vagrant vagrant   25 Nov 15 00:23 bar
drwxr-xr-x. 2 root    root    4096 Nov 15 00:35 baz
-rw-r--r--. 1 root    root       0 Nov 15 00:23 foo
```

Now everybody can read our secret message! Oh no! Now let us change the
permissions so nobody can read, write to, or execute our secret message. To do
this we are going to run the following command:

```bash
[vagrant@devops-bootcamp ~]$ chmod 000 bar
[vagrant@devops-bootcamp ~]$ ls -l
total 8
----------. 1 vagrant vagrant   25 Nov 15 00:48 bar
drwxr-xr-x. 2 root    root    4096 Nov 15 00:35 baz
-rw-r--r--. 1 root    root       0 Nov 15 00:23 foo
[vagrant@devops-bootcamp ~]$ cat bar
cat: bar: Permission denied
```

By passing `000` as the permissions for `bar` in the `chmod` command we have
set it so nobody can interact with the file... unless we change the permissions
again.

If you did not get the error message `cat: bar: Permission denied` you are
probably running the command as root-- Stop that! You are ruining the guide! :)

```bash
[vagrant@devops-bootcamp ~]$ chmod 700 bar
[vagrant@devops-bootcamp ~]$ ls -l
total 8
-rwx------. 1 vagrant vagrant   25 Nov 15 00:48 bar
drwxr-xr-x. 2 root    root    4096 Nov 15 00:35 baz
-rw-r--r--. 1 root    root       0 Nov 15 00:23 foo
[vagrant@devops-bootcamp ~]$ cat bar
A secret message!
```

Now we are the only people that can see our secret message! This is because we
set the mode from NOBODY READ/WRITE/EXECUTE to OWNER READ/WRITE/EXECUTE.

Our next task is to make the file `foo` editable by everybody without owning it.
Instead of using the ### method with `chmod` we will use the `ugoa` controls.

```bash
[vagrant@devops-bootcamp ~]$ sudo chown a+w foo
[vagrant@devops-bootcamp ~]$ ls -l
total 8
-rwx------. 1 vagrant vagrant   25 Nov 15 00:48 bar
drwxr-xr-x. 2 root    root    4096 Nov 15 00:35 baz
-rw-rw-rw-. 1 root    root       0 Nov 15 00:23 foo
```

The command we wrote added the (w)rite permission to (a)ll users on the system,
so now we are able to write to the file.

Finally we are going to make a directory private for root by removing the
e(x)ecute permission for (a)ll users on a directory. First we are going to
move `foo` from our $HOME dir to the `baz` dir, then we are going to change the
permissions on the file.

```bash
[vagrant@devops-bootcamp ~]$ sudo mv foo baz/
[vagrant@devops-bootcamp ~]$ sudo chmod a-x baz
[vagrant@devops-bootcamp ~]$ sudo chmod u+x baz
[vagrant@devops-bootcamp ~]$ ls -l
total 8
-rwx------. 1 vagrant vagrant   25 Nov 15 00:48 bar
drwxr--r--. 2 root    root    4096 Nov 17 19:25 baz
[vagrant@devops-bootcamp ~]$ ls baz
ls: cannot access baz/foo: Permission denied
total 0
-????????? ? ? ? ?            ? foo
```

What we have done here is move `foo` to the `baz` directory, then removed the
execute permission for (a)ll users, re-added the execute permission for the 
owner `root`. When we try to ls the `baz` directory we are not able to see
its contents correctly because we do not have permission to do so.

If you have any questions look at the `man` pages for each of the topics
covered or search their common usage online.
