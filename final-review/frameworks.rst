Web Frameworks Challenge Guide
==============================

* :code:`cd` to the directory where you'd like your flask application
  to be, make a virtualenv and install flask

.. code-block:: 

    virtualenv venv
    source venv/bin/activate
    pip install flask

* Open a file :code:`hello.py` (or whatever you'd like to call it), 
  and stick the following inside:

.. code-block:: python

    from flask import Flask
    app = Flask(__name__)

    @app.route("/")
    def hello():
        return "Hello World!"

        if __name__ == "__main__":
            app.run()

* Run :code:`python hello.py`, and go to 
  `127.0.0.1:5000 <http://127.0.0.1:5000>`_ to see your application.
  The application will automagically update as you develop, so you
  don't need to run that every time you make a change.  Just edit 
  your app in a different window. 

* Flask uses `Jinja templates <http://jinja.pocoo.org/>`_.  For
  examples of how to create a jinja template, what they can do, 
  and where in your project they should go, check out 
  `systemview <https://github.com/devopsbootcamp/systemview>`_.

* To direct your user to another page, the

.. code-block:: python
    @app.route("/")

line is what creates a new page. You can read more about routing,
and how to render pages `here <http://flask.pocoo.org/docs/0.10/quickstart/#routing>`_.  


