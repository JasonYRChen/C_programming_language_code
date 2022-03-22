#include <stdio.h>

void convert_to_bits(long, int *);
void print_bits(int *, int, const char *);
int len(long);
long right_rotate(long, int);

void convert_to_bits(long num, int bits[])
{
    int i, left, right, temp;
    
    for (i = 0; num; i++, num >>= 1)
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

int len(long num)
{
    int length;
    for (length = 0; num; length++, num >>= 1)
        ;
    return length;
}

long right_rotate(long num, int range)
{
    long high_value, low_value, high_mask, low_mask;

    high_mask = (~0 >> range) << range;
    low_mask = ~high_mask;
    high_value = (num & high_mask) >> range;
    low_value = (num & low_mask) << (len(num) - range);
    return high_value + low_value;
}

int main()
{
    long num = 111;
    int range = 5;
    long rotated;
    int num_bits[sizeof(long) * 8];
    int rotated_bits[sizeof(long) * 8];

    if (range > len(num))
        range = len(num);
    rotated = right_rotate(num, range);
    convert_to_bits(num, num_bits);
    convert_to_bits(rotated, rotated_bits);
    printf("Original number: %li, rotated number: %li\n", num, rotated);
    printf("Rotate unit: %i\n", range);
    print_bits(num_bits, len(num), "Original");
    print_bits(rotated_bits, len(num), "Rotated ");

    return 0;
}

