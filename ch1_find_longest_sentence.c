#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_WORDS 100

void error(char *);
int max_words(FILE *, char *);
void copy(char *, char*);

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int max_words(FILE *file, char *destination)
{
    if (dup2(0, 10) == -1) /* copy stdin to descriptor table no.10 */
        error("Cannot duplicate stdin to slot no.10");
    if (dup2(fileno(file), 0) == -1)
        error("Cannot assign file descriptor to slog no.0");

    int count = 0;
    int i;
    char c;
    char temp[MAX_WORDS];
    for (i = 1; (c = getchar()) != EOF; i++) {
        temp[i - 1] = c;
        if (c == '\n') {
            if (i > count) {
                count = i;
                temp[i] = '\0';
                copy(temp, destination);
            }
            i = 0;
        }
    }

    if (dup2(10, 0) == -1) /* restore stdin */
        error("Cannot restore stdin to slot no.0");

    return count;
}

void copy(char *from, char *to)
{
    int i;
    for (i = 0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }
    to[i] = '\0';
}

int main()
{
    char destination[MAX_WORDS];
    FILE *file = fopen("text.txt", "r");

    int words = max_words(file, destination);
    printf("The maximum line: %s\nWord count: %i\n", destination, words);

    return 0;
}

