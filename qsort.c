#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int, int);
void qsort_inplace(int *, int);
void random_array(int, int *, int);
void print_array(int *, int, char *);

void print_array(int array[], int length, char *title)
{
    int i;
    printf("%s: ", title);
    for (i = 0; i < length; i++)
        (i == length - 1)? printf("%i\n", array[i]): printf("%i, ", array[i]);
}

void random_array(int base, int array[], int length)
{
    int i;
    for (i = 0; i < length; i++) 
        array[i] = rand_int(base, i);
}

int rand_int(int base, int seed)
{
    if (base <= 0)
        fprintf(stderr, "'base' cannot be smaller than or equal to zero.");
    if (!seed)
        seed = base;
    srand(time(NULL) * seed);
    return rand() % base;
}

void qsort_inplace(int array[], int length)
{
    int head = 0;
    int tail = length - 1;
    int mid = rand_int(length, array[length-1]);
    int target;
    int left = 0;
    int right = tail - 1;
    int exchange;
    
    target = array[mid];
    array[mid] = array[tail];
    while (left <= right) {
        while ((left <= right) && (array[left] <= target))
            left++;
        while ((left <= right) && (array[right] > target))
            right--;
        if (left <= right) {
            exchange = array[left];
            array[left] = array[right];
            array[right] = exchange;
            left++;
            right--;
        }
    }
    array[tail] = array[left];
    array[left] = target;

    if (left)
        qsort_inplace(array, left);
    if ((length - left - 1) > 1)
        qsort_inplace(array + left + 1, length - left - 1);
}

int main()
{
    int length = 9;
    int array[length];
    int base = 100;
    random_array(base, array, length);
    print_array(array, length, "Before qsort");
    qsort_inplace(array, length);
    print_array(array, length, "After qsort");

    return 0;
}

