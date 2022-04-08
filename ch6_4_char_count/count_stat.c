#include <stdio.h>
#include "char_count.h"

void show_stat(struct key keys[], int table_length, int unidentified)
{
    struct key *p = keys;
    int i;
    for (i = 0; i++ < table_length; p++) {
        if (p->count) {
            (p == keys)? printf("\\n: "): printf("%c: ", p->name);
            printf("%i\n", p->count);
        }
    }
    if (unidentified)
        printf("Unidentified: %i\n", unidentified);
}

