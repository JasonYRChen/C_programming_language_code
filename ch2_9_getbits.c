#include <stdio.h>

long getbits(long num, int position, int length)
{
    long temp = num;
    int bits;
    
    for (bits = 0; temp; bits++)
        temp = temp >> 1;

    if (position < 0) {
        fprintf(stderr, "Position cannot be negative.");
        return 1;
    } else if ((position - 1) > bits)
        position = bits - 1;

    if (length > position + 1)
        length = position + 1;

    return ((num >> (position + 1 - length)) & ~(~0 << length));
}

int main()
{
    printf("%li\n", getbits(15, 12, 2));

    return 0;
}

