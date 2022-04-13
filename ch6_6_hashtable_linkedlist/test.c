#include <stdio.h>
#define base 5

void test(char *msg[])
{
    for (int i=0; i < base; i++) {
        msg[i] = "a";
    }
}

int main()
{
    char *msg[base];
    test(msg);
    for (int i=0; i<base; i++)
        printf("%s\n", msg[i]);

    return 0;
}

