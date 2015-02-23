Clean Up Systemview
===================

The systemview web application has some style issues. Let's install `flake8`,
a Python linter and fix them.
Remember to activate your virtualenv before installing!

.. code-block:: bash

    $ source ~/env/bin/activate
    (env)$ pip install flake8
    (env)$ flake8 .

Now, run

.. code-block:: bash
    $ git checkout debugging

and try running the application again

.. code-block:: bash
    $ python systemview.py

Oh no!  We get a 500 Internal Server Error!  Basically, something
with the backend of our application (the systemview.py file)
is broken (and we've turned debugging off so flask won't 
tell us what it is).  This is where pdb comes in handy!  

Uncomment :code:`pdb.set_trace()` on line 185 in systemview.py, and try running the application again.
This time, you'll be dropped into a debugging repl (read-eval-print-loop).
This is the python debugger!  From here we can run commands such
as :code:`where` to print the stack trace, :code:`break [line no]`
to insert a new break point (a point where you stop the program
and see what's going on), and :code:`step` to execute the current
line.  You can 
`read all about pdb here <https://docs.python.org/2/library/pdb.html>`_, 
or type :code:`help [command]` to see what a command does. 

For this particular problem, we'll want to print out some information
about the Search class to see what's going on.  First we'll try 

.. code-block:: bash

    (Pdb) print Search

which just tells us that the search class is in the main function, 
which isn't very helpful.  But let's try looking at the query
that Search is making:

.. code-block:: bash

    (Pdb) print Search.query

And now we can see what the error is! The SQL url (set at the top
of the file in app.config) is invalid.  Let's change it back to 
:code:`sqlite:///./systemview.db`.  Type Ctrl+d to exit the 
Pdb repl, and try running the app again.  It should run
normally now!



