/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int *result = malloc(numsSize * sizeof(int));
    int count = 0;
    int i, index;

    for (i = 0; i < numsSize; i++)
    {
        index = abs(nums[i]) - 1;

        if (nums[index] < 0)
        {
            // We have already seen this number
            result[count] = abs(nums[i]);
            count++;
        }
        else
        {
            // Mark this number as visited
            nums[index] = -nums[index];
        }
    }

    *returnSize = count;

    return result;
}