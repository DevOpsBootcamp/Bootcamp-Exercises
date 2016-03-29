CC=gcc
CFLAGS= -O0 -Wall -g -std=c99


all: ast_tests

ast:
	$(CC) -c ast.c -o ast.o $(CFLAGS)

ast_tests: ast
	$(CC) ast_tests.c ast.o -o ast_tests $(CFLAGS)

tests: ast_tests

clean:
	rm -f ast.o
	rm -f ast_tests
	rm -rf ast_tests.dSYM
