Beginning Git Exercises
=======================

First make sure you have git by running 
```sh
$ git --version
```

If git is not installed, install it by running
```sh
$ sudo yum install git
```

Now that you have git, make a directory, cd to it, and run
```sh 
git init
```
This will create a new subdirectory `.git` which holds all the necessary
repository files -- settings, commits, branches, etc.  This is the 
skeleton of your git repository, and where all the information is held.
Feel free to look through the files in there, and see what's going on!
Just be careful to not delete anything.

Now that we have a repository, let's add some content to it!  Make a new
file, either with vim
```sh
$ vim myfile
```
or with touch
```sh
$ touch myfile
```
To add this file to our git repository so that git tracks the file, we run
```sh
$ git add myfile
```
This basically tells git to see our file, and know that it's there. Each
time we commit, we'll add the files we want to commit first to tell git
which files we want to be included in the commit. Without adding them,
git won't save our changes. 

Now we'll commit the file to the repository.  Committing stores the 
current contents of the files you've added along with a message about
the changes you've made.  
```sh
$ git commit
```
This should open a file in your text editor with some information in it.  
The very top line is where you'll enter your commit message -- be specific!
 It's important that you and anyone you are working with be able to
read the commit message and get a good idea of what changes you made. 

Below your commit message is information about what files and changes
are being committed.  It's not a bad idea to look over this and make sure
everything is in place before committing.


Lastly, we'll clone someone elses repository. If
someone else is working on a project you think is awesome, or you need
to get someone's repo for any reason, you'll want to clone it.  You can
find the url to clone from on the right hand side bar on github.
```sh
$ git clone git@github.com:DevOpsBootcamp/Bootcamp-Exercises.git
```
This will create a directory called Bootcamp-Exercises in your current
directory which will have all the data from the latest version of the 
git repo.  If you want to clone it into a different directory, you can
run
```sh
$ git clone git@github.com:DevOpsBootcamp/Bootcamp-Exercises.git mydirectory
```

Excellent!  Now that we know the basics, let's got to the User Info 
exercise and test our knowledge.

