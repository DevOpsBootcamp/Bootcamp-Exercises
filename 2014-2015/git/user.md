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
$ git checkout <branch name>
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

You should now have a fork of the repository in your own account 
(github.com/<your username>/Students), and be on a branch named after you. 
Ask one of us for help if you aren't sure if you did it right!

Next we'll go over making a pull request.  Go back to 
https://github.com/DevOpsBootcamp/Students.  There will likely be a 
bar across the top of the page saying "<branch name> (a few minutes ago)" 
with a large "Compare & pull request" button on the left.  Go ahead 
and click the button.  If that doesn't show up, then go to
the 'pull requests' link on the right hand side menu (it's the third
item down).  

This should take you to a page with some nice information on it.  At 
the very top of the page, right below the name of the account and repo,
you can see the two branches you're comparing -- yours, and the master
branch of our repository.  Below that is the name of your pull request
(you can change it!) and any comments you have.  Just like with 
commit messages, you want to be as clear as possible about what you're
doing! Make sure you have a brief summary in the title section, and 
more details about what you did in the comments.  Then, on the right,
you'll see if you are able to merge the branch -- in this case, you should
be able to!  Once you've filled out the form, you can click 'Create
Pull Request' to submit the pull request!

Below all of that are the details of what you changed -- you can see
all of the files you changed, as well as the specific line-by-line
changes that you made.  It's not a bad idea to skim through these and 
make sure that everything looks correct!  

Now, you will wait for your pull request to be pulled into the repo 
by the owners (in this case, that's us!).  We can also make comments
on the pull request, and even add other commits!  Let's try it!

If you head over the the pull requests link in the sidebar (if you aren't
already there), and click on your pull request, you'll see a space towards the bottom of the page to make comments.  Go ahead and type something
out to leave a comment ("Hi, I like elephants" or "Double-chocolate
brownies are awesome" or a cat gif are acceptable comments).  

If you refresh the page, you'll see your comment on the PR!  

Now, head back to your terminal, and use git status to make sure
you are still on the branch that you created.  Open up your 
file and change something about it -- maybe add a line, delete a line,
add your middle name, whatever floats your boat.  Save and close the
file, then push your file with it's changes to the same branch 
(git add, git commit, git push origin <branch>).  

If you go back to the pull request on our repository, you should see 
your new commit in the pull request!  You can click on it to see
changes you made in more detail.  Pretty neat!   

Now, dedicated DevOps attendees, you are enlightened Github users!  Go
forth and submit PRs!  


