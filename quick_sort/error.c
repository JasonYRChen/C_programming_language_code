#include <stdlib.h>
#include <stdio.h>
#include "qsort.h"

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
