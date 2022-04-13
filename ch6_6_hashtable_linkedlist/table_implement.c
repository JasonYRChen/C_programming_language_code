#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

void initialize_table(struct node *table[])
{
    int i;
    for (i = 0; i < BASE; i++) {
        table[i] = malloc(sizeof(struct node));
        if (!table[i])
            error("Lack of memory. Cannot malloc new space.\n");
    }
}

struct node *seek(char *key, struct node *table[])
{
    unsigned int index = hashit(key);
    struct node *pointer = table[index];
    
    while (pointer && pointer->key) {
        if (!string_compare(key, pointer->key))
            return pointer;
        pointer = pointer->next;
    }
    return NULL;
}

void set(char *key, char *value, struct node *table[])
{
    unsigned int index = hashit(key);
    struct node *p_prev, *p_current;
    p_prev = p_current = table[index];
    
    while (p_current && p_current->key) {
        if (!string_compare(key, p_current->key)) {
            p_current->value = value;
            return ;
        }
        p_prev = p_current;
        p_current = p_current->next;
    } 

    if (!p_current) {
        p_prev->next = p_current = malloc(sizeof(struct node));
        if (!p_current)
            error("Lack of memory. Cannot malloc new space.\n");
    }

    p_current->key = key;
    p_current->value = value;
}

void free_node(struct node *node)
{
    if (node && (node->next))
        free_node(node->next);
    printf("---To free node \"%s\"---\n", node->key);
    free(node);
}

