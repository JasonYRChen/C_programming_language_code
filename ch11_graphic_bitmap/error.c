#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
