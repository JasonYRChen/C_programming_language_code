#include <stdio.h>

int len(long);
long invert(long, int, int);
void convert_to_bits(long, int *);
void print_bits(int *, int, const char *);

int len(long num)
{
    int length = 0;
    for (; num; length++)
        num >>= 1;
    return length;
}

long invert(long num, int position, int range)
{
    int i;
    long mask = 0;

    if (position > (len(num) - 1))
        position = len(num) - 1;
    if (range > (position + 1))
        range = position + 1;
    for (i = 0; i < range; i++)
        mask = mask * 2 + 1;
    mask <<= position + 1 - range;
    
    int bits[sizeof(long) * 8];
    convert_to_bits(mask, bits);
    print_bits(bits, len(mask), "mask");
    
    return num ^ mask;
}

void convert_to_bits(long num, int bits[])
{
    int i, left, right, temp;
    for (i = 0; num; num >>= 1, i++)
        bits[i] = num % 2;
    for (left = 0, right = i - 1; left < right; left++, right--) {
        temp = bits[left];
        bits[left] = bits[right];
        bits[right] = temp;
    }
}

void print_bits(int bits[], int length, const char *name)
{
    int i;
    printf("%s bits: ", name);
    for (i = 0; i < length; i++)
        printf("%i", bits[i]);
    printf("\n");
}

int main()
{
    long num = 120;
    long result;
    int position = 4;
    int range = 8;
    int num_bits[sizeof(long) * 8];
    int result_bits[sizeof(long) * 8];

    printf("Position: %i, range: %i\n", position, range);

    convert_to_bits(num, num_bits);
    print_bits(num_bits, len(num), "num ");
    result = invert(num, position, range);
    convert_to_bits(result, result_bits);
    print_bits(result_bits, len(result), "ans ");

    return 0;
}

