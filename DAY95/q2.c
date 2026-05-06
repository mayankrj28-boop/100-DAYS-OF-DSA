/**
 * Note: The returned value should be an integer.
 */

#include <limits.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize) {

    if (numsSize < 2)
        return 0;

    // Find minimum and maximum element
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] < minVal)
            minVal = nums[i];

        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    // If all elements are same
    if (minVal == maxVal)
        return 0;

    // Bucket size and count
    int bucketSize = (maxVal - minVal) / (numsSize - 1);

    if (bucketSize == 0)
        bucketSize = 1;

    int bucketCount =
        (maxVal - minVal) / bucketSize + 1;

    // Bucket arrays
    int* bucketMin =
        (int*)malloc(bucketCount * sizeof(int));

    int* bucketMax =
        (int*)malloc(bucketCount * sizeof(int));

    int* used =
        (int*)calloc(bucketCount, sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Put elements into buckets
    for (int i = 0; i < numsSize; i++) {

        int index =
            (nums[i] - minVal) / bucketSize;

        if (nums[i] < bucketMin[index])
            bucketMin[index] = nums[i];

        if (nums[i] > bucketMax[index])
            bucketMax[index] = nums[i];

        used[index] = 1;
    }

    // Find maximum gap
    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {

        if (!used[i])
            continue;

        int gap = bucketMin[i] - prevMax;

        if (gap > maxGap)
            maxGap = gap;

        prevMax = bucketMax[i];
    }

    // Free memory
    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}
