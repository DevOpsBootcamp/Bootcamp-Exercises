DOBC Docker Exercise
====================

In this directtory there are two files:

* README.rst: This document
* Dockerfile: The dockerfile specification for your container.

In this exercise you will create a docker container which contains and runs the
`tinsy-flask-app`_ we played with previously.

.. _`tinsy-flask-app`: https://github.com/DevOpsBootcamp/tinsy-flask-app

The Exercise
------------

Extend the dockerfile so that it completes the following tasks:

* Clones https://github.com/DevOpsBootcamp/tinsy-flask-app.git into the
  ``/root`` directory. \*

* Installs the dependencies needed for that application (you can install them
  system-wide, not in a virtualenv. Bonus points for installing in a
  virtualenv. \*

  * This will involve installing packages with ``apt`` and with ``pip``.

* Exposes the correct ports.

* Runs the correct ``CMD`` on startup.

\* HINT: Do this step manually to avoid playing the guessing game.

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
