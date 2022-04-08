#include <stdio.h>
#include "char_count.h"

struct key keys[] = {{'\n', 0},
                     {' ', 0},
                     {'a', 0},
                     {'b', 0},
                     {'c', 0},
                     {'d', 0},
                     {'e', 0},
                     {'f', 0},
                     {'g', 0},
                     {'h', 0},
                     {'i', 0},
                     {'j', 0},
                     {'k', 0},
                     {'l', 0},
                     {'m', 0},
                     {'n', 0},
                     {'o', 0},
                     {'p', 0},
                     {'q', 0},
                     {'r', 0},
                     {'s', 0},
                     {'t', 0},
                     {'u', 0},
                     {'v', 0},
                     {'w', 0},
                     {'x', 0},
                     {'y', 0},
                     {'z', 0}
                    };

int main(int argc, char *argv[])
{
    FILE *text;
    struct key *target;
    char c;
    int unidentified = 0;

    if (!(text = fopen(argv[1], "r")))
        error("File not found.");

    while ((c = fgetc(text)) != EOF) {
        c = case_convert(c);
        target = bisearch(c, keys, keys + 27);
        if (target)
            target->count++;
        else
            unidentified++;
    }
    show_stat(keys, 28, unidentified);

    return 0;
}

