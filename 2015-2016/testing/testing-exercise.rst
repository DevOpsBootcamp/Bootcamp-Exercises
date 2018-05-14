Software Testing Exercise
=========================

For this, we'll walk you through getting `Travis CI`_ set up on
on of your repositories.

1.  The first thing you'll need is to create a repository on github,
	and name it something helpful so you can remember what it does!
	Don't worry about adding a license, but do put a little blurb
	in the Description box about what the repo is for, and opt to
	create a README.

2. Then, in your repo you'll want to add a :code:`.travis.yml` file
   to your repo.  For example, the travis file for our systemview
   app will look something like this:

.. code-block:: yaml

    language: python
    python:
        - 2.6
        - 2.7
        - 3.4
        - pypy
        - pypy3
        - asdfasdf
    matrix:
        allow_failures:
            - python: asdfasdf
        fast_finish: true
    script: py.test adder/lib.py

3. When you open a pull request on your repo, travis will use this
   file to automatically run your tests. It will clone your repo
   into a fresh virtual machine, install your dependencies, use
   the version of python you specify, and then run your unit tests
   and verify that everything is looking good!

4. Try it out, and let us know if you have any troubles!
   To see Travis in action, check out 
   the tinsy flask app Travis at 
   https://travis-ci.org/DevOpsBootcamp/tinsy-flask-app

.. _Travis CI: https://travis-ci.org/
.. _travis demo: https://github.com/elijahcaine/travis-demo
