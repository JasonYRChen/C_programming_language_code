#include <stdio.h>

void itoa(int num, char string[], int width)
{
    int i = 0, sign = 0, left ,right, exchange;

    if (num < 0)
        sign = 1, num *= -1;

    do {
        string[i++] = (num % 10) + '0';
    } while (num /= 10);
    if (sign)
        string[i++] = '-';

    while (i < width)
        string[i++] = ' ';
    string[i] = '\0';

    for (left = 0, right = i - 1; left < right; left++, right--) 
        exchange = string[left], string[left] = string[right], string[right] = exchange;
}

int main()
{
    int num = 29339;
    char string[sizeof(int) + 2];
    int width = 10;
    printf("num: %i\n", num);

    itoa(num, string, width);
    printf("converted:%s\n", string);

    return 0;
}

