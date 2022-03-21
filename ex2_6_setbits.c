#include <stdio.h>
#include <stdlib.h>

/*
This code still has bug while 'num' is smaller than 'position' or 'range'.
But debug take a pause now. 
*/

int min(int n1, int n2)
{
    if (n1 >= n2)
        return n2;
    else
        return n1;
}    

int len(long num)
{
    if (num == 0)
        return 1;

    int length;
    for (length = 0; num; length++) {
        num = num >> 1;
    }
    return length;
}

void transfer_to_bits(long num, int bits[])
{
    int i, left, right, temp; 
    int length = len(num);

    for (i = 0; num; i++) {
        bits[i] = num % 2;
        num = num >> 1;
    }

    left = 0;
    right = length - 1;
    
    for (; left < right; left++, right--) {
        temp = bits[left];
        bits[left] = bits[right];
        bits[right] = temp;
    }
}

long setbits(long num, int position, int range, long template)
{
    int length_num = len(num);
    int length_template = len(template);
    long mask = 0;
    int i;

    if (position > (length_num - 1))
        position = length_num - 1;
    if (range > min(position + 1, min(length_num, length_template)))
        range = min(position + 1, min(length_num, length_template));
    
    for (i = 0; i < range; i++)
        mask = mask * 2 + 1;
    template = (template & mask) << (position + 1 - range);
    mask = ~(mask << (position + 1 - range));
    num = (num & mask) | template;

    return num;
}

int main(int argc, char *argv[])
{
    long num = atol(argv[1]);
    long template = atol(argv[4]);
    int position = atoi(argv[2]);
    int range = atoi(argv[3]);
    long result = setbits(num, position, range, template);
    int i;

    int num_bits[sizeof(long) * 8];
    int temp_bits[sizeof(long) * 8];
    int result_bits[sizeof(long) * 8];
    transfer_to_bits(num, num_bits);
    transfer_to_bits(template, temp_bits);
    transfer_to_bits(result, result_bits);

    printf("Number's bits: ");
    for (i = 0; i < len(num); i++)
        printf("%i", num_bits[i]);
    printf("\ntemplate bits: ");
    for (i = 0; i < len(template); i++)
        printf("%i", temp_bits[i]);
    printf("\nresult's bits: ");
    for (i = 0; i < len(num); i++)
        printf("%i", result_bits[i]);
    

    return 0;
}

