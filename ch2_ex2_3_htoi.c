#include <stdio.h>

long htoi(char *hex)
{
    int i;
    long total = 0;
    long temp;
    char c;

    if (hex[0] == '0' && ((hex[1] == 'x') || (hex[1] == 'X')))
        hex = hex + 2;

    for (i = 0; *hex != '\n' && *hex != '\0'; i++, hex++) {
        c = *hex;
        temp = -1;
        if ((c >= 'a') && (c <= 'f'))
            c = c - 'a' + 'A';

        if ((c >= 'A') && (c <= 'F')) 
            temp = 10 + (long)(c - 'A');
        else if ((c >= '0') && (c <= '9'))
            temp = (long)(c - '0');
        else {
            fprintf(stderr, "Invalid hex number: %c\n", c);
            return -1;
        }

        total = total * 16 + temp;
    }
    
    return total;
}

int main()
{
    char hex[50];
    long decimal;

    printf("Enter a hex number: ");
    scanf("%49s", hex);
    decimal = htoi(hex);
    if (decimal == -1)
        return 1;
    printf("The decimal number is: %li\n", decimal);

    return 0;
}

