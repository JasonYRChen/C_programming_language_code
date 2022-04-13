#include "hashtable.h"

unsigned int hashit(char *key)
{
    unsigned int hash_value = 0;
    unsigned int prime = 31;

    for (; *key; key++) 
        hash_value = *key + prime * hash_value;
    return hash_value % BASE;
}

