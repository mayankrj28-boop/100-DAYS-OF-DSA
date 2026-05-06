#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
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

        // Right element is smaller
        if (arr[j].value < arr[i].value) {

            temp[k++] = arr[j++];
            rightCount++;
        }
        else {

            // Count smaller elements
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

// Merge Sort function
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

int main() {

    int nums[] = {5, 2, 6, 1};

    int n = sizeof(nums) /
            sizeof(nums[0]);

    struct Node arr[n];
    struct Node temp[n];

    int count[n];

    // Initialize nodes and count array
    for (int i = 0; i < n; i++) {

        arr[i].value = nums[i];
        arr[i].index = i;

        count[i] = 0;
    }

    // Perform merge sort
    mergeSort(arr, 0, n - 1,
              count, temp);

    printf("Count of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
