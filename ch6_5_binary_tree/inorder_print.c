#include "bin_tree.h"
#include <stdio.h>

void inorder_print(struct node *node)
{
    if (node->left)
        inorder_print(node->left);
    printf("Node: %s, count: %i\n", node->name, node->count);
    if (node->right)
        inorder_print(node->right);
}

