#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

