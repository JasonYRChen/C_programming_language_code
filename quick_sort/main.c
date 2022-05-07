#include "qsort.h"

int integer_compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}    

int string_compare(const void *x, const void *y)
{
    return strcmp(*(char **)x, *(char **)y);
}

int test_compare(const void *x, const void *y)
{
    return strcmp(((struct test *)x)->name, ((struct test *)y)->name);
}

int main()
{
    char *array[] = {"abcd", "Abcd", "aBcd", "ABcd"};
    int unit = sizeof(char *);
    enum type t = CHAR;
    int (*cmp)(const void*, const void*) = string_compare;

    //int array[] = {8, -1, 5, 0, 3, 7, 3, 6};
    //int unit = sizeof(int);
    //enum type t = INT;
    //int (*cmp)(const void*, const void*) = integer_compare;

    //struct test array[] = {{"Jim", 20}, {"Tina", 17}, {"Bob", 10}};
    //int unit = sizeof(struct test);
    //enum type t = TEST;
    //int (*cmp)(const void*, const void*) = test_compare;

    int length = sizeof(array) / unit;

    printf("Before sorting:\n");
    print_array(array, length, unit, t);
    quick_sort(array, length, unit, cmp);
    printf("After sorting:\n");
    print_array(array, length, unit, t);

    return 0;
}

