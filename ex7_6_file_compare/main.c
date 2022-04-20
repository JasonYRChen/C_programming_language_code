#include "compare.h"
#include <stdio.h>

int main()
{
    char *f1_in = "msg4";
    char *f1_out = "diff1";
    char *f2_in = "msg3";
    char *f2_out = "diff2";

    int length = file_compare(f1_in, f1_out, f2_in, f2_out);
    show("diff1", "diff2", length); 

    return 0;
}

