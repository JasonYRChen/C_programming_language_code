#include <stdio.h>

int main()
{
    char a = 'a';
    int i = 0;

    int h = ((a == '\0') || (a == '\n'))? i: ++i;
    printf("h: %i, i: %i", h, i);

    return 0;
}
