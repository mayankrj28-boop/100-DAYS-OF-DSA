/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */

#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size,
                       int* arr2, int arr2Size,
                       int* returnSize) {

    // Frequency array
    int count[1001] = {0};

    // Store frequency of arr1 elements
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    // Result array
    int* result = (int*)malloc(arr1Size * sizeof(int));

    int index = 0;

    // Place elements according to arr2 order
    for (int i = 0; i < arr2Size; i++) {

        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Place remaining elements in ascending order
    for (int i = 0; i <= 1000; i++) {

        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;

    return result;
}
