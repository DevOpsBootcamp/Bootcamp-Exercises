Software Testing Exercise
=========================

For this, we'll walk you through getting `Travis CI`_ set up on
on of your repositories.

1.  The first thing you'll need is to create a repository on github. 
    You can either make your own, or you can clone our `travis demo`_
    repository:

.. code-block:: none

    git@github.com:ElijahCaine/travis-demo.git

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

.. _Travis CI: https://travis-ci.org/
.. _travis demo: https://github.com/elijahcaine/travis-demo
