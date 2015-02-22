Fixing memory leaks with Valgrind and GDB
=========================================

*Hard mode activated.*

I'm writing an interpreter. An interpreter builds and abstract syntax tree from
my source code. It's just a tree data structure, nothing fancy. In my code, a
token is the data held by an individual node in the tree.

We are interested in two files, `ast.c` and `ast_tests.c`. The first is the
implementation of the tree, and the second is a series of working tests for the
tree.

Even though the tests pass, there are two memory leaks. We're going to fix
them.
