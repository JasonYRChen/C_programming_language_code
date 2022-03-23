#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char string[], int length)
{
    int left, right, temp;
    if (!length)
        length = strlen(string);

    for (left = 0, right = length - 1; left < right; left++, right--)
        temp = string[left], string[left] = string[right], string[right] = temp;
}

void itob(int num, char string[], int base)
{
    int residue, sign, i = 0;
    if (num < 0)
        sign = 1, num *= -1;

    do {
        residue = (num % base) + '0';
        if (residue > '9')
            residue = residue - '0' - 10 + 'a';
        string[i++] = residue;
    } while (num /= base);
    if (sign)
        string[i++] = '-';
    string[i] = '\0';

    reverse(string, i);
}

int blanks_in_string(long limit)
{
    int count;
    for (count = 0; limit; count++, limit /= 10)
        ;
    return count + 2;
}

int main()
{
    int num = -63;
    char string[blanks_in_string(INT_MAX)];
    int base = 8;

    itob(num, string, base);
    printf("Number: %i, number to base %i string: %s\n", num, base, string);

    return 0;
}

