#include <stdlib.h>
#include "bin_tree.h"

void free_postorderly(struct node *node)
{
    if (node->left)
        free_postorderly(node->left);
    if (node->right)
        free_postorderly(node->right);

    free(node->name);
    free(node);
}
