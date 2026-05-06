#include <stdio.h>

// Merge function to count inversions
long long merge(int arr[], int temp[],
                int left, int mid, int right) {

    int i = left;      // Left subarray
    int j = mid + 1;   // Right subarray
    int k = left;

    long long invCount = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // Remaining elements in left subarray
            // are greater than arr[j]
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Merge Sort function
long long mergeSort(int arr[], int temp[],
                    int left, int right) {

    long long invCount = 0;

    if (left < right) {

        int mid = (left + right) / 2;

        // Left half
        invCount += mergeSort(arr, temp, left, mid);

        // Right half
        invCount += mergeSort(arr, temp, mid + 1, right);

        // Merge and count inversions
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {

    int arr[] = {8, 4, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];

    long long inversions =
        mergeSort(arr, temp, 0, n - 1);

    printf("Number of Inversions = %lld",
           inversions);

    return 0;
}
