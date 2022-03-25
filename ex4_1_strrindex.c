#include <stdio.h>

int len(char *string)
{
    int length = 0;
    for (; *string != '\0'; length++, string++)
        ;
    return length;
}

int strrindex(char *string, char *target)
{
    int s_end = len(string) - 1;
    int t_end = len(target) - 1;
    int s_index, t_index;

    for (; s_end >= t_end; s_end--) {
        t_index = t_end, s_index = s_end;
        for (; (t_index >= 0) && (string[s_index] == target[t_index]); s_index--, t_index--) 
            ;
        if (t_index == -1)
            return ++s_index;
    }
    return -1;
}

int main()
{
    char *string = "abc def";
    char *target = " a";
    int index = strrindex(string, target);
    
    (index != -1)? printf("Index: %i\n", index): printf("Not found\n");

    return 0;
}

