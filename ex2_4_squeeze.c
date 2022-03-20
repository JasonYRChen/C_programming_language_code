#include <stdio.h>

void squeeze(char *s1, char *s2)
{
    int i, j, loc;
    for (j = 0; s2[j] != '\0'; j++) {
        for (loc = i = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[j])
                s1[loc++] = s1[i];
        s1[loc] = '\0';
    }
}

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    char *s2 = argv[2];

    printf("Deleted: %s\n", s1);
    printf("Deleter: %s\n", s2);
    squeeze(s1, s2);
    printf("Deleted: %s\n", s1);

    return 0;
}

