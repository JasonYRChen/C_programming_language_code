#include <stdio.h>
#include "hashtable.h"

int main()
{
    char *kv_pair[][2] = {{"a", "apple"}, {"b", "ball"}, {"c", "circle"}, {"ac", "abort"}, {"b", "boy"}, {"co", "come"}, {"z", "zebra"}};
    int length = 7;
    int i;
    char *k;
    struct node *table[BASE], *v;

    initialize_table(table); /* fill in blank node pointer into table */

    set(kv_pair[0][0], kv_pair[0][1], table);

    for (i = 0; i < length; i++) 
        set(kv_pair[i][0], kv_pair[i][1], table); 

    for (i = 0; i < length; i++) {
        k = kv_pair[i][0];
        v = seek(k, table);
        printf("key: %s, hash: %u, value: %s\n", k, hashit(k), (v)? v->value: "NULL");
    }

    v = seek("op", table);
    printf("key: %s, hash: %u, value: %s\n", "op", hashit("op"), (v)? v->value: "NULL");
    return 0;
}

