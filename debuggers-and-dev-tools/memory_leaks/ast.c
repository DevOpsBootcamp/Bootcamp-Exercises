#include "ast.h"
/*
    val must not be NULL. children are optional and must be ast_nodes.
*/
struct ast_node* make_node(struct token *val, size_t num_children, ...) {
    struct ast_node *new_node = malloc(sizeof(struct ast_node));
    new_node->val = val;
    new_node->num_children = num_children;
    // pointers are small, so allocating extra space is cheap
    new_node->children_cap = num_children + 2;
    new_node->children = malloc(sizeof(struct ast_node) * num_children);
    va_list children;
    va_start(children, num_children);
    for (size_t i = 0; i < num_children; i++) {
        new_node->children[i] = va_arg(children, struct ast_node*);
    }
    va_end(children);
    return new_node;
}

void append_child(struct ast_node *node, struct ast_node *val) {
    if (node->num_children == node->children_cap) {
        node->children_cap *= 2;
        realloc(node->children, node->num_children * 2);
    }
    node->children[node->num_children] = val;
    node->num_children++;
}

/*
    Recursively free all nodes and values.
*/
void delete_node(struct ast_node *node) {
    for (size_t i = 0; i < node->num_children; i++) {
        delete_node(node->children[i]);
    }
    free(node->children);
    free(node->val);
    free(node);
}
