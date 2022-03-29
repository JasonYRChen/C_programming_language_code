#include <stdio.h>

char *str_cat(char *s, char *t)
{
    char *head = s;

    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
    return head;
}

int main()
{
    char s[100] = "This is a test.";
    char *t = "I hope it passes.";
    char *test = str_cat(s, t);

    printf("in s: %s\n", s);
    printf("in test: %s\n", test);

    return 0;
}

