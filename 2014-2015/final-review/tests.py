#!/usr/bin/python

import unittest

def example(x):
    return 100+x

def func(x):
    if isinstance(x, str):
        return "Hello "+x
    elif isinstance(x, int):
        return 2*x+1
    else:
        return False

class ExampleTest(unittest.TestCase):
    def test(self):
        self.assertEqual(example(3), 103)
    # This is where you should write your tests

if __name__ == '__main__':
    unittest.main()
