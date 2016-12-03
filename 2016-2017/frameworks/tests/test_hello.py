import unittest
from app import app

class HelloTestCase(unittest.TestCase):

    def setUp(self):
        self.app = app.test_client()

    def test_hello(self):
        rv = self.app.get('/hello/bob')
        assert 'Hello bob!!' in rv.data

if __name__ == '__main__':
    unittest.main()
