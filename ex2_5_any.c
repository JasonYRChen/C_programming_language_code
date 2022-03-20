#include <stdio.h>

char *any(char *s1, char *s2)
{
    char *temp;
    for (; *s1 != '\0'; s1++) 
        for (temp = s2; *temp != '\0'; temp++) 
            if (*s1 == *temp)
                return s1;

    return NULL;
}

int main(int argc, char *argv[])
{
    char *pointer = any(argv[1], argv[2]);
    if (pointer)
        printf("Character matched: %s\n", pointer);
    else
        printf("No match\n");
    

    return 0;
}

