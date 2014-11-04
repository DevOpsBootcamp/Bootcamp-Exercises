Git User Exercise
=================

Go to https://github.com/DevOpsBootcamp/Students and click the `fork` 
button in the top right corner.  This will create a copy of the repository
in your own account on github.  The difference between cloning and 
forking is that forking make a copy of the repo and makes you the owner, 
whereas cloning means that the project is still part of the main
repository.  

Clone your version of the Students repository

Now we're going to make a branch.  Branches are basically just different
versions of the same repository.  They are useful for working on different
parts of your project separately, keeping different contributors work
separated, and avoiding merge conflicts.  To make a branch, run

```sh
$ git branch <your name>
$ git branch -l (or --list)
```

You should see your new branch in the list of branches!  However, the 
asterisk by master indicates that you are still on the master branch. 
To go to your new branch, run

```sh
$git checkout <branch name>
```

Now you're on your very own branch!  

Make a new file in vim

```sh
$ vim <your name>.txt
```

and then add some data about yourself

```sh
Name: Lucy Wyman
Year and major: Sophomore in Computer Science
What you hope to learn at Bootcamp: 
Miscellaneous Information:
```

Save and close your file, then git add and commit it.  (For a refresher
on how to do this, go to the beginner git document).  When you push, 
though, you'll want to specify your branch so that it gets pushed to 
the remote.

```sh
$ git push origin <your branch name>
```

Now, if you go to github and click on the branches dropdown menu, you 
should see your branch in the list!

Next we'll go over making a pull request.  


