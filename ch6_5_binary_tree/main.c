#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "Not enough argument");
        return 1;
    }

    struct node *root = create_node(*++argv, 0, NULL, NULL);
    struct node *pointer;
    int result;

    /* build binary tree */
    for (argc--; argc; argc--, argv++) {
        pointer = root;
        while ((result = compare_string(*argv, pointer->name))) {
            if ((result < 0) && !(pointer->left))
                pointer->left = create_node(*argv, 0, NULL, NULL);
            else if ((result > 0) && !(pointer->right))
                pointer->right = create_node(*argv, 0, NULL, NULL);
            pointer = (result < 0)? pointer->left: pointer->right;
        }
        pointer->count++;
    }

    inorder_print(root); /* print the tree inorderly */
    free_postorderly(root); /* free heap inside the tree */

    return 0;
}

