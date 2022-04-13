#include "hashtable.h"

int string_compare(char *s1, char *s2)
{
    for (; *s1; s1++, s2++)
         if (*s1 - *s2)
             return *s1 - *s2;
    return *s1 - *s2;
}

