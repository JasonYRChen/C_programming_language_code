#include "bitmap.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int len_bitmap = atoi(argv[1]);
    int bits = atoi(argv[2]);
    int bitmap[len_bitmap];

    initialize_bitmap(bitmap, len_bitmap, bits);
    command(bitmap, len_bitmap, bits);

    return 0;
}

