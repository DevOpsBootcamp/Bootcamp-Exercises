Python Basics
=============

There are two ways to run python code:

#. A REPL (read eval print loop)
#. From a script

To open a REPL, just run

.. code-block:: none

    $ python
    Python 2.7.9 (default, Apr  2 2015, 15:33:21)
    [GCC 4.9.2] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>>

And some information about your python version and other details should pop up.
The **>>>** is your command prompt -- it tells you that python is ready to
execute your commands!

Your challenge is to open a REPL:

#. Make a list of the months of the year
#. Print "<name> was born in <month>" using variables for your name and
   birth-month
#. Print the entire list of months, with a new line between each one, using a
   for loop.
#. Print all the months that start with "M"
#. Find the square root of 84

Even more of a challenge:

#. Generate a list of the first 10 prime numbers
#. Generate a list of the first 10 Fibonacci numbers
#. Print your name to a file
#. Read your name from a file

If you want to keep challenging yourself, check out `Project Euler`_ coding
puzzles.

.. _Project Euler: https://projecteuler.net/archives


Next we'll look at writing python scripts. A script
is a list of commands which can be executed
without user interaction (though they can take user
input!).  So when you write a python script, you're
telling the python interpreter to "Run each of these
commands in order, from top to bottom".  This differs
from a compiled language, such as C.  Python scripts
aren't inherently different from typing commands into
the REPL, but they allow you to share your code
with others, run the script several times, modify it
and so on.

To start writing a python script, open a file
:code:`bootcamp.py` and add (or copy) this:

.. code-block:: python

    #!/usr/bin/python3
    # This can tell your interpreter which python binary to use

    print("This is your first command!")

Now you can add commands to your script as if you 
were typing them in the REPL!  

Try the first exercise you did in the REPL as a script.

To run your script, the incantation is:

.. code-block:: none

    $ python bootcamp.py

Once you've successfully run the first exercise from
the REPL as a script, here are a few more exercises to 
try:

#. Create a list (as long as you want!), then programmatically
   find how long it is.
#. Append a new number to the end of your list and make sure
   your algorithm works.
#. Define a function :code:`length()` that takes one argument
   and finds how long it is.
#. Define a function :code:`sum()` that will sum all the elements
   in a list
