Configuration Management Challenge Guide
========================================

Installing the `Chef development kit <https://downloads.chef.io/chef-dk/>`_
can be non-trivial, but try to be patient and stick it out until it's
working.

* `Download <https://downloads.chef.io/chef-dk/redhat/#/>`_ the 
   development kit.  Note that you'll want to install it from the 
   download and not through a package manager.
* To get started on your first cookbook, you'll want to cd to the 
  directory you want your cookbook to be in, and run
  :code:`chef generate cookbook my-cookbook`.  
* If you :code:`cd my-cookbook` and run :code:`ls -a`, there 
  should be several files, including :code:`.kitchen.yml`. For 
  general cookbook development, you'd want to hit up both the RH 
  family and debian, but for now, we'll just use ubuntu. Remove the 
  line for centos
  
.. code-block:: 

    - name: centos-6.4

* :code:`kitchen list` should output something like this:

.. code-block:: 

    Instance             Driver   Provisioner  Last Action
    default-ubuntu-1204  Vagrant  ChefSolo     <Not Created>

* The other thing you'll want to change in your configuration file
  is this:

.. code-block::

    run_list:
      - recipe[bar::default]

To this:

.. code-block::

    run_list:
      - recipe[chefdk_getting_started]

* To create a virtual machine according to the chefdk getting started
  cookbook, and make sure that you've set Chef up right, run 
  :code:`kitchen create all`
  You can confirm it worked by

.. code-block::

    kitchen list
    Instance             Driver   Provisioner  Last Action
    default-ubuntu-1204  Vagrant  ChefSolo     Created

* Notice that the instance is created now!

* In the future, to test changes you make to a cookbook, you'll want
  to use :code:`kitchen converge`.
* You can find a finished cookbook for systemview `here <https://github.com/DevOpsBootcamp/deploy-systemview>`_
* For documentation and more help getting started with test kitchen,
  the tool you'll use to develop your cookbook, check out 
  `kitchen.ci <http://kitchen.ci/docs/getting-started/>`_
