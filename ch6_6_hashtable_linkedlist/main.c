/*
If 'BASE' in hashtable.h is changed, remember to compile all the .o file again, especially
hashit.o, even 'make file' suggests the version is the latest. .o file will not change its
'BASE' value once its compile is over, so any change of 'BASE' after that will not affect
the value in .o files.
*/

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

    /* build hash table */
    for (i = 0; i < length; i++) 
        set(kv_pair[i][0], kv_pair[i][1], table); 

    /* show values of existing keys in hash table */
    for (i = 0; i < length; i++) {
        k = kv_pair[i][0];
        v = seek(k, table);
        printf("key: %s, hash: %u, value: %s\n", k, hashit(k), (v)? v->value: "NULL");
    }

    /* show value (which should be 'NULL') of not existing key in hash table */
    v = seek("op", table);
    printf("key: %s, hash: %u, value: %s\n", "op", hashit("op"), (v)? v->value: "NULL");

    /* free nodes built with 'malloc' */
    for (i = 0; i < BASE; i++)
        free_node(table[i]);

    return 0;
}

