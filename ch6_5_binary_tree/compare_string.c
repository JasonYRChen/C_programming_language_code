#include "bin_tree.h"

int compare_string(char *s1, char *s2)
{
    for (; *s1 != '\0'; s1++, s2++) 
         if (*s1 - *s2)
             return *s1 - *s2;
    if (*s2)
        return -*s2;
    return 0;
}

