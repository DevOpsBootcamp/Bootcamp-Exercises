Continuous Integration Challenge Guide
======================================
Now that you have (hopefully) completed the Testing review challenges we can
move on to Continuious integration.


Activity 0: Create a Travis CI Account (with your GH account)
-------------------------------------------------------------
Before we can do *anything* with Travis CI (and continuious integration as a
whole) you need to sign up for a Travis CI account. This is really easy if you
already have a GitHub account, just go to https://travis-ci.org/ and click the
`Sign Up` button in the middle of the page.


Activity 1: Setup Travis CI integration testing with your simple python script+tests
------------------------------------------------------------------------------------
First we are going to write a really simple python app and push it to a GitHub
repository and set it up for Travis CI to automatically test.

**Steps:**

1. Create the repository
#. Setup TravisCI with your application
#. Create your python application
#. Test your python application
#. Integration Testing

**Create the Repository:**

Begin by going to GitHub, creating a repository, and naming it
'dobc-travis-test'. Feel free to include a README and a LICENSE, but they
aren't strictly necessary for our purposes.

Once you have the repo follow these steps to turn on Travis CI integration: 1.
Click on `Settings` on the bottom right above the git clone link
#. Navigate to `Webhooks & Service` 
#. Under `Services` click `Add a Service` and add `Travis CI`.

Now navigate to tps://travis-ci.org/profile and click the `sync` button. Under
the list of repositories toggle `<username>/dobc-travis-test` from ✗ to ✓.

You now have Travis CI setup with your (empty) repository. Beware, Travis is
only triggered by Pushes to the repository, so there won't be any Travis builds
until we make our first push to master.

**The Python Application Part:**

After you clone the repo into your VM, create a directory in your git repo
called 'adder'. This is the name of our super simple python app. If you were
able to make it to the testing demo you might have seen a lot of this code
before.

Before getting started, cd into the `adder` directory and run the following
commands to create and enter a virtual environment.

.. code::

    $ virtualenv venv
    $ source venv/bin/activate
    $ pip install pytest

**NOTE:** If you do not yet have virtualenv installed, run the following
commands to get it installed. You will need to run the previous commands once
the correct programs have been installed.

.. code::

    $ wget http://download.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm
    $ sudo rpm -ivh epel-release-6-8.noarch.rpm
    $ sudo yum install -y python-pip python-virtualenv

The adder directory needs to contain the following files: `__init__.py`,
`lib.py`, and `tests.py`. `__init__.py` and `tests.py` are both empty, so you
can create them with the command `touch __init__.py tests.py`. `lib.py` should
containt he following code:

.. code::

    import unittest


    def add(a, b):
        return a + b


    class TestAdd(unittest.TestCase):

        def test_it_works(self):
            assert add(1, 2) == 3

        def test_negative(self):
            assert add(1, -2) == -1

What we've done with our application is made a python package by including
`__init__.py` in the directory, and we've told pytest that this directory
contains a python package with tests that should be run.

Now `cd` back to the root directory of your repository and run the command `pip
freeze > requirements.txt`. Next open a file called `.travis.yml` which
contains the following code:

.. code::

    language: python
    python:
        - 2.6
        - 2.7
        - 3.4
    matrix:
        fast_finish: true
    script: py.test adder/lib.py

The above config file essentually tells Travis CI to run our test suite using
python 2.6, 2.7, and 3.4, and to run py.test adder/lib.py for our tests.

Before you make a commit and `git push origin master` you can run the command
py.test adder/lib.py just to be sure the testing infrastructure works locally.
It's always safe to test locally before pushing a change like this.

Now once you've pushed you should see a the builds automatically start on
Travis. If you don't you'll need to read some docs and figure out where in the
process things fell apart. Don't worry, it usually takes a whlie for any
project to get setup with Integration Testing, nobody gets it right on the
frist try.

There you ahve it! Now every time you push changes to this repository your
tests will be run automatically and GitHub will even tell you if the tests
don't pass.


Activity 2: Setup Travis CI integration testing with your Systemview app+tests
------------------------------------------------------------------------------
Now that you've got a basic app setup with Integration Testing, go ahead and
with the tests you wrote for a fork of python-webapp (if you didn't already you
should write tests for python-webapp) setup integration testing.


Resources:
----------
https://github.com/mythmon/travis-demo :: example code
http://docs.travis-ci.com/ :: reference docs
