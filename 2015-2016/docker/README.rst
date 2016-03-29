DOBC Docker Exercise
====================

In this directory there are two files:

* README.rst: This document
* Dockerfile: The dockerfile specification for your container.

In this exercise you will create a docker container which contains and runs the
`tinsy-flask-app`_ we played with previously.

**NOTE:** This exercise is not a trick question. If you read the README on the
``tinsy-flask-app`` page it will basically tell you what to do, your job is to
write a Dockerfile that accomplishes the same task as setting up and running this
app.

.. _`tinsy-flask-app`: https://github.com/DevOpsBootcamp/tinsy-flask-app

The Exercise
------------

Extend the dockerfile so that it completes the following tasks:

#. Install system wide dependencies for application (``python-pip``, ``git``, etc).

#. Clones https://github.com/DevOpsBootcamp/tinsy-flask-app.git into the
   ``/root`` directory.

#. Install app-specific dependencies
   (``pip install -r /root/tinsy-flask-app/requirements.txt``)

#. Exposes the correct ports (Check which ports the app defaults to broadcasting on)

#. Runs the correct ``CMD`` on startup (What does the ``tinsy-flask-app`` README say
   to run to star the app?)

**HINT:** Don't write the Dockerfile without manually running the setup commands,
otherwise you're basically playing the guessing game ("are these the commands I
want to run? How about these?")

Running The Thing
-----------------

To test your docker container run the following command:

.. code-block:: text

    $ docker build -t <myname/dobc> .
    [... lots of build output ...]
    $ docker run -it -p <local port>:<docker port> <myname/dobc>
    [... output from the process in the docker container ...]

To enter a shell in your already built container run the following command:

.. code-block:: text

    $ docker run -it -p <local port>:<docker port> <myname/dobc> /bin/bash

References
----------

* https://docs.docker.com/
* https://docs.docker.com/engine/reference/builder/
