#include "bin_tree.h"
#include <stdlib.h>

/*
"malloc" is used to copy name to node's name.
Remember to "free" it at the end of the code.
*/

struct node *create_node(char *name, int count, struct node *left, struct node *right)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->name = copy_string(name);
    new_node->count = count;
    new_node->left = left;
    new_node->right = right;

    return new_node;
}

