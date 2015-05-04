#ifndef AST_H
#define AST_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

struct token {
    int type; // An integer representing the type of the token
    double value; // A double value of the token
};


struct ast_node {
    struct token *val;
    size_t num_children;
    size_t children_cap;
    struct ast_node **children;
};

struct ast_node* make_node(struct token *val, size_t num_children, ...);
void append_child(struct ast_node *node, struct ast_node *val);
void delete_node(struct ast_node *node);
void ast_post_map(struct ast_node *node, void (*func)(struct ast_node*));
void ast_pre_map(struct ast_node *node, void (*func)(struct ast_node*));
#endif
