#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int *deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, rear = -1;

    int *result = (int*)malloc(sizeof(int) * numsSize);
    int resSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        // remove out of window
        if (front <= rear && deque[front] <= i - k)
            front++;

        // remove smaller elements
        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        // store result
        if (i >= k - 1)
            result[resSize++] = nums[deque[front]];
    }

    *returnSize = resSize;
    return result;
}
