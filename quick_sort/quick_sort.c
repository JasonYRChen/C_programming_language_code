#include "qsort.h"

void print_array(void *array, size number, size width, enum type t)
{
    int i;

    switch (t) {
        case INT:
            for (i = 0; i < number; i++) 
                printf((i == number - 1)? "%i\n": "%i, ", ((int *)array)[i]);
            break;
        case CHAR:
            for (i = 0; i < number; i++) 
                printf((i == number - 1)? "%s\n": "%s, ", ((char **)array)[i]);
            break;
        case TEST:
            //struct test *arr = (struct test *)array;
            for (i = 0; i < number; i++) {
                printf("Name: %s, age: %i\n", ((struct test *)(array + i * width))->name, ((struct test *)(array + i * width))->age);
            }
            break;
        default:
            error("Unknown format.");
    }
}

void quick_sort(void *base, size number, size width, int (*compare)(const void *, const void*))
{
    if (number < 2)
        return;

    void *pivot = malloc(width);
    void *temp = malloc(width);
    int index;
    void *left = base;
    void *right = base + (number - 2) * width;

    // select and save pivot element, then save the last element to pivot position 
    srand(time(NULL));
    index = rand() % number;
    memcpy(pivot, base + index * width, width);
    memcpy(base + index * width, base + (number - 1) * width, width);

    // do in-place sorting
    while (left <= right) {
        while ((left <= right) && (compare(left, pivot) <= 0))
            left += width;
        while ((left <= right) && (compare(right, pivot) > 0))
            right -= width; 
        if (left <= right) {
            memcpy(temp, left, width);
            memcpy(left, right, width);
            memcpy(right, temp, width);
            left += width;
            right -= width;
        }
    }

    // insertion found for pivot -> switch current element to the end -> insert pivot
    memcpy(base + (number - 1) * width, left, width);
    memcpy(left, pivot, width);

    // next round divide-and-conquer
    quick_sort(base, (left - base) / width, width, compare);
    quick_sort(left + width, number - (left - base) / width - 1, width, compare);

    free(temp);
    free(pivot);
}

