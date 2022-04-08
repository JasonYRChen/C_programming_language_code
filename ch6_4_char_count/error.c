#include <stdlib.h>
#include <stdio.h>
#include "char_count.h"

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

