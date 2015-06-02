Testing Challenge Guide
=======================

* In general you'll be using the python `unit test library <https://docs.python.org/dev/library/unittest.html>`_ 
  to write unit tests in python.  Just add 

.. code-block:: python
    
    import unittest

to the top of your test script, and you should be good to go.

* Open up `tests.py <https://github.com/DevOpsBootcamp/Bootcamp-Exercises/blob/final-review/final-review/tests.py>`_ and add your own
  tests to test :code:`func(x)`.  You can follow the example, but
  make sure that the tests you add are still part of the ExampleTest
  class.  Using python's unittest library, your tests will just be 
  testing the output of a specific function to make sure it has the
  output you expect.  This is what :code:`assertEquals` does.  For
  example:
  
.. code-block:: python

  import unittest
  
  class TestStringMethods(unittest.TestCase):
  
    def test_upper(self):
      self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
      self.assertTrue('FOO'.isupper())
      self.assertFalse('Foo'.isupper())

    def test_split(self):
      s = 'hello world'
      self.assertEqual(s.split(), ['hello', 'world'])
      # check that s.split fails when the separator is not a string
      with self.assertRaises(TypeError):
          s.split(2)

* For other tools you can use to write tests in python, check out
  `this awesome guide <http://docs.python-guide.org/en/latest/writing/tests/>`_ on writing tests in python.  
