#include "ast.h"
#include <stdio.h>

#define RED "\x1B[0;31m"
#define GREEN "\x1B[0;32m"
#define NOCOLOR "\x1B[0m"

#define EXPECT_EQ(a, b) printf("Test %s == %s ", (#a), (#b));\
if ((a) == (b)) {\
    printf(" %sPassed%s\n", GREEN, NOCOLOR);\
}\
else {\
    printf(" %sFailed%s\n", RED, NOCOLOR);\
}

// Different types of tokens - we don't care what they are.
const int tok_eof = 0,
          tok_def = 1,
          tok_extern = 2,
          tok_identifier = 3,
          tok_number = 4,
          tok_dbl = 5,
          tok_string = 6,
          tok_punc = 10;


void test_make_node();
void test_delete_node();
void test_append_child();

int main() {
    test_make_node();
    test_append_child();
    test_delete_node();
}

void test_make_node() {
    struct token *t0 = malloc(sizeof(struct token));
    t0->type = tok_number;
    t0->value = 0;
    struct token *t1 = malloc(sizeof(struct token));
    t1->type = tok_number;
    t1->value = 1;
    struct token *t2 = malloc(sizeof(struct token));
    t2->type = tok_number;
    t2->value = 2;
    struct token *t3 = malloc(sizeof(struct token));
    t3->type = tok_number;
    t3->value = 3;
    struct ast_node *n0 = make_node(t0, 0);
    EXPECT_EQ(n0->val, t0);
    EXPECT_EQ(n0->num_children, 0);
    EXPECT_EQ(n0->children_cap, 2);
    struct ast_node *n1 = make_node(t1, 1, n0);
    EXPECT_EQ(n1->val, t1);
    EXPECT_EQ(n1->num_children, 1);
    EXPECT_EQ(n1->children_cap, 3);
    EXPECT_EQ(n1->children[0], n0);
    struct ast_node *n2 = make_node(t2, 2, n0, n1);
    EXPECT_EQ(n2->val, t2);
    EXPECT_EQ(n2->num_children, 2);
    EXPECT_EQ(n2->children_cap, 4);
    EXPECT_EQ(n2->children[0], n0);
    EXPECT_EQ(n2->children[1], n1);
    struct ast_node *n3 = make_node(t3, 3, n0, n1, n2);
    EXPECT_EQ(n3->val, t3);
    EXPECT_EQ(n3->num_children, 3);
    EXPECT_EQ(n3->children_cap, 5);
    EXPECT_EQ(n3->children[0], n0);
    EXPECT_EQ(n3->children[1], n1);
    EXPECT_EQ(n3->children[2], n2);
    free(t0);
    free(t1);
    free(t2);
    free(t3);
    free(n0->children);
    free(n0);
    free(n1->children);
    free(n1);
    free(n2->children);
    free(n2);
    free(n3->children);
    free(n3);
}

void test_append_child() {
    struct token *t0 = malloc(sizeof(struct token));
    struct ast_node *n0 = make_node(t0, 0);
    struct token *t1 = malloc(sizeof(struct token));
    struct ast_node *n1 = make_node(t1, 0);
    EXPECT_EQ(n0->num_children, 0);
    append_child(n0, n1);
    EXPECT_EQ(n0->num_children, 1);
    EXPECT_EQ(n0->children_cap, 2);
    EXPECT_EQ(n0->children[0], n1);
    struct token *t2 = malloc(sizeof(struct token));
    struct ast_node *n2 = make_node(t2, 0);
    struct token *t3 = malloc(sizeof(struct token));
    struct ast_node *n3 = make_node(t3, 0);
    struct token *t4 = malloc(sizeof(struct token));
    struct ast_node *n4 = make_node(t4, 0);
    append_child(n0, n2);
    EXPECT_EQ(n0->num_children, 2);
    EXPECT_EQ(n0->children_cap, 2);
    EXPECT_EQ(n0->children[1], n2);
    append_child(n0, n3);
    EXPECT_EQ(n0->children_cap, 4);
    printf("%zu\n", n0->children_cap);
    EXPECT_EQ(n0->num_children, 3);
    EXPECT_EQ(n0->children[2], n3);
    append_child(n0, n4);
    EXPECT_EQ(n0->children_cap, 4);
    EXPECT_EQ(n0->num_children, 4);
    EXPECT_EQ(n0->children[3], n4);
    free(n0->children);
    free(n0);
    free(t0);
    free(n1->children);
    free(n1);
    free(t1);
    free(n2->children);
    free(n2);
    free(t2);
    free(n3->children);
    free(n3);
    free(t3);
    free(n4->children);
    free(n4);
    free(t4);
}

void test_delete_node() {
    struct token *t0 = malloc(sizeof(struct token));
    struct ast_node *n0 = make_node(t0, 0);
    struct token *t1 = malloc(sizeof(struct token));
    struct ast_node *n1 = make_node(t1, 1, n0);
    delete_node(n1);
}
