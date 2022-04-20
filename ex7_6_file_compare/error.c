#include <stdio.h>
#include <stdlib.h>
#include "compare.h"

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

