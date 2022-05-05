#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int size;
struct test {char *name; int age;};
enum type {INT, CHAR, TEST};

void quick_sort(void *, size, size, int (*compare)(const void *, const void *));
void error(char *);
void print_array(void *, size, size, enum type);
