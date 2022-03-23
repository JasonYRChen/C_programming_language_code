#include <stdio.h>

int binary_search(int target, int nums[], int length)
{
    int left = 0;
    int right = length - 1;
    int mid = (left + right) / 2;

    while ((left <= right) && (nums[mid] != target)) {
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }

    return (nums[mid] == target)? mid: -1;
}

int main()
{
    int nums[] = {1, 3, 5, 7, 9};
    int target = 2;
    int length = 5;
    int index = binary_search(target, nums, length);

    (index == -1)? printf("Not found\n"): printf("Index: %i\n", index);    

    return 0;
}

