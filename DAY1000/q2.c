/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */

#include <stdlib.h>

// Structure to store value and index
struct Node {
    int value;
    int index;
};

// Merge function
void merge(struct Node arr[],
           int left,
           int mid,
           int right,
           int count[],
           struct Node temp[]) {

    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        // Right element smaller
        if (arr[j].value < arr[i].value) {

            temp[k++] = arr[j++];
            rightCount++;
        }
        else {

            // Add smaller count
            count[arr[i].index] += rightCount;

            temp[k++] = arr[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {

        count[arr[i].index] += rightCount;

        temp[k++] = arr[i++];
    }

    // Remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Merge Sort
void mergeSort(struct Node arr[],
               int left,
               int right,
               int count[],
               struct Node temp[]) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    // Left half
    mergeSort(arr, left, mid,
              count, temp);

    // Right half
    mergeSort(arr, mid + 1, right,
              count, temp);

    // Merge halves
    merge(arr, left, mid, right,
          count, temp);
}

int* countSmaller(int* nums,
                  int numsSize,
                  int* returnSize) {

    *returnSize = numsSize;

    int* result =
        (int*)calloc(numsSize,
                     sizeof(int));

    struct Node arr[numsSize];
    struct Node temp[numsSize];

    // Initialize nodes
    for (int i = 0; i < numsSize; i++) {

        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Merge sort
    mergeSort(arr, 0, numsSize - 1,
              result, temp);

    return result;
}
