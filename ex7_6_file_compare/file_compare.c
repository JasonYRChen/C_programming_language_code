#include <stdio.h>
#include <stdlib.h>
#include "compare.h"
#define max(a, b) (a >= b)? (a): (b) //use explicit type to catch the result or error occurs

/* 
A problem would be there is no way to know at the beginning the maximum word numbers
per line. Here I use 'char_max', 'malloc' and 'free' to control the word numbers in
buffer.
*/

int digits(int num)
{
    int i;
    for (i = 0; num; i++)
        num /= 10;
    return i;
}

char *allocate(int unit_in_char, char *msg)
{
    char *buffer;
    msg = (msg)? msg: "Allocation failed.";
    if ((buffer = malloc(sizeof(char) * unit_in_char)) == NULL)
        error(msg);
    return buffer;
}

char *reallocate(char *old_buffer, int length, int unit_in_char)
{
    char *new_buffer, *p_new, *p_old;
    int i;

    new_buffer = p_new = allocate(unit_in_char, "Reallocate failed.");
    p_old = old_buffer;
    
    for (i = 0; i < length; i++) 
        *p_new++ = *p_old++;

    free(old_buffer);
    
    return new_buffer;
} 

int file_compare(char *f1_in_name, char *f1_out_name, char *f2_in_name, char *f2_out_name)
{
    // return char_max for further application

    FILE *f1_in = fopen(f1_in_name, "r");
    FILE *f1_out = fopen(f1_out_name, "w");
    FILE *f2_in = fopen(f2_in_name, "r");
    FILE *f2_out = fopen(f2_out_name, "w");
    int char_max = 20; // max characters number per line, may be adjusted afterward
    char *fwrite;
    char *buffers[] = {allocate(char_max, ""), allocate(char_max, "")};
    char c[2];
    FILE *f_in[] = {f1_in, f2_in};
    FILE *f_out[] = {f1_out, f2_out};
    int i, length, index[2], line_no = 1, flag_diff = 0, digit = 0;
    int f_EOF[] = {0, 0};

    for (; !f_EOF[0] || !f_EOF[1]; line_no++) {
        // initialization for new line
        index[0] = index[1] = 0;
        c[0] = c[1] = 'a';

        // comparison line-by-line
        while ((!f_EOF[0] && c[0] != '\n') || (!f_EOF[1] && c[1] != '\n')) {
            // refresh c[i] and check EOF
            // beware of necessity of "c[i] != '\n'" at the beginning of 'if' condition
            for (i = 0; i < 2; i++) 
                if ((c[i] != '\n') && (c[i] = fgetc(f_in[i])) == EOF && !f_EOF[i])
                    f_EOF[i] = 1;

            // raise difference flag
            if ((c[0] != c[1]) && !flag_diff)
                flag_diff = 1;

            // reallocate to larger memory banks
            if ((length = max(index[0], index[1])) >= char_max - 2) {
                char_max = char_max * 3 / 2;
                buffers[0] = reallocate(buffers[0], index[0], char_max);
                buffers[1] = reallocate(buffers[1], index[1], char_max);
            }

            // write in buffers only if not the end of line
            for (i = 0; i < 2; i++) 
                if (!f_EOF[i] && (c[i] != '\n'))
                    buffers[i][index[i]++] = c[i];
        }

        // save the differences into files if any
        if (flag_diff) {
            fwrite = allocate(char_max + 1 + digits(line_no), "");
            for (i = 0; i < 2; i++) {
                buffers[i][index[i]++] = '\n';
                buffers[i][index[i]] = '\0';
                sprintf(fwrite, "%i %s", line_no, buffers[i]);
                fprintf(f_out[i], "%s", fwrite);
            }
            free(fwrite);
            flag_diff = 0;
        }
    }

    for (i = 0; i < 2; i++)
        free(buffers[i]);

    fclose(f1_in);
    fclose(f1_out);
    fclose(f2_in);
    fclose(f2_out);

    return char_max + digit + 1;
}

int len(char *word)
{
    int count;
    for (count = 0; *word++ != '\0'; count++)
        ;
    return count;
}

void show(char *f1_name, char *f2_name, int len_words)
{
    // The trick here is to ignore '\n' in each line.
    // Read carefully the positions of 'c[i] = fgetc(f[i])'

    FILE *f1 = fopen(f1_name, "r");
    FILE *f2 = fopen(f2_name, "r");
    FILE *f[] = {f1, f2};
    char f1_temp[len_words], f2_temp[len_words], c[] = {'a', 'a'};
    char *f_temp[] = {f1_temp, f2_temp};
    int i, index[2];

    // Titles in each file names
    printf("\nFILE NAME: %s%*s|FILE NAME: %s\n", f1_name, len_words - len(f1_name) - 11, " ", f2_name);
    // seperation line
    for (i = 0; i < (2 * len_words + 1); i++)
        (i == (2*len_words))? printf("-\n"): printf("-"); 

    while (c[0] != EOF || c[1] != EOF) {
        index[0] = index[1] = 0;
        for (i = 0; i < 2; i++) {
            c[i] = fgetc(f[i]);
            // write while c is not EOF nor '\n'
            while (c[i] != EOF && c[i] != '\n') {
                f_temp[i][index[i]++] = c[i];
                c[i] = fgetc(f[i]);
            }
            f_temp[i][index[i]] = '\0'; // make ending
        }
        // print the differences
        printf("%s%*s|%s\n", f_temp[0], len_words - len(f_temp[0]), "", f_temp[1]);
    }

    fclose(f1);
    fclose(f2);
}

