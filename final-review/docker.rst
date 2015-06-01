Docker Challenge Guide
======================
Docker is an awesome alternative to running processes in a Virtual Machine. If
you haven't already check out the slides we did on Docker and 

Getting Started with Docker
---------------------------
If you have no already managed to get a virtual machine setup with DOBC either
flag one of the DOBC teachers in the room, check the previous lesson from Fall
term on setting up a VM, or ask about getting a VM setup in the #devopsbootcamp
irc channel on irc.freenode.net. 


Activity 1: Successfully login to a docker container
----------------------------------------------------
Your goal for this activity is to download a docker container, launch the
container, and manage to get into a shell prompt within the container.

**Steps:**
1. Install `docker-io` package
#. Fetch a docker image
#. Spin up a docker container
#. Login to the docker container

To install Docker you should be able to simply run the following commands shell
commands in the `DevOps BootCamp Vagrant Machine`_:

.. code::

    $ sudo su
    # wget http://download.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm
    # rpm -ivh epel-release-6-8.noarch.rpm
    # yum -y install docker-io
    # service docker start
    # chkconfig docker on

Now we will download an ubuntu image to run inside of the docker image
(distro-ception!!!)

.. code::

    # docker pull ubuntu

You may get an error when trying to pull the ubuntu image from the docker
servers. Wait a minute and try again, it should work fine :)

Now that we have downloaded a docker image we can start to play around with it.

.. code::

    # docker run ubuntu echo hello world
    hello world
    # docker run -d ubuntu sleep 300
    # docker ps
    CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
    f578a9c7e37e        ubuntu:14.04        "sleep 300"         6 seconds ago       Up 6 seconds                            sharp_goldstine
    # docker attach sharp_goldstine

First we spun up an Ubuntu docker container and ran the command `echo hello
world` which, as you can imagine, printed hello world to the screen.  Next we
have done here is started an Ubuntu docker container which is running the
process `sleep 300` which means it'll 'sleep' for 5 minutes. If we didn't pass
the `-d` flag to this command though we would need to wait 5 minutes for the
process to finish and get our shell back but we were able to daemonize the
process and fiddle around while it ran.

Before we wrap up Activity 1 we will do what we just did, but with a
`Dockerfile`, which is similar to a Vagrantfile in that you can automate the
setup of an environment in code without having to run commands manually every
time you want to work.

Using the text editor of your choice (vi, vim, nano, anything works), open a
file called `Dockerfile` and populate it with these contents:

.. code::

    MAINTAINER <your name>
    FROM ubuntu
    RUN echo building my first docker container!
    ADD . /dobc/

Next open a file and fill it with anything you like and call it whatever you
like (but not Dockerfile, that breaks things)

.. code::

    Hello docker, I am at DevOps BootCamp yay...

Finally run these commands:

.. code::

    # docker build .
    # docker images
    REPOSITORY          TAG                 IMAGE ID            CREATED             VIRTUAL SIZE
    <none>              <none>              4351b699807c        50 seconds ago      188.4 MB
    # docker run -i -t 4351b699807c /bin/bash
    root@4351b699807c:/# ls /
    bin  boot  dev  dobc  etc  home  lib  lib64  media  mnt  opt  proc  root  run  sbin  srv  sys  tmp  usr  var
    root@4351b699807c:/# cd dobc
    root@4351b699807c:/# ls
    Dockerfile my_awesome_file
    root@4351b699807c:/# cat my_awesome_file
    Hello docker, I am at DevOps BootCamp yay...
    root@4351b699807c:/# exit

And there you have it! You successfully built a docker image with a Dockerfile,
spun up a container of it, and logged in to look around the container.

.. _DevOps BootCamp Vagrant Machine: https://github.com/DevOpsBootcamp/Vagrant


Activity 2: Deploy Systeview with Docker (and a Dockerfile)
-----------------------------------------------------------
With this activity we are going to give you a little less guidence but we think
you can make it work!

Your goal to complete this challenge is to take your newly gained Docker-Fu and
deploy the `Systemview application`_! It won't be easy, but I trust that if you
look at the docker documentation and pace yourself this will be a fulfilling.

.. _Systemview application: https://github.com/devopsbootcamp/systemview


Resources
---------
https://www.docker.com/tryit/ :: getting started docs
https://docs.docker.com/ :: reference docs
https://docs.docker.com/reference/builder/ :: specific reference docs
