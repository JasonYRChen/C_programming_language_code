#include <stdlib.h>
#include "bin_tree.h"

char *copy_string(char *string)
{
    char *copied = malloc(sizeof(string));
    int i;
    
    for (i = 0; *string != '\0'; i++) 
        copied[i] = *string++;
    
    return copied;
}

