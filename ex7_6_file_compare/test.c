#include <stdio.h>

int main()
{
    char msg[] = {'\0', '\0', '\0', '\0'};
    FILE *f_out = fopen("test_msg", "w");
    fprintf(f_out, "%s", msg);
    fclose(f_out);

    FILE *f_in = fopen("test_msg", "r");
    char c;
    int i = 0;
    while ((c = fgetc(f_in)) != EOF)
        i++;
    printf("i = %i\n", i);
    fclose(f_in);

    return 0;
}
