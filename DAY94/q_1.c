#include <stdio.h>

// Function to find maximum element
int findMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Counting Sort Function
void countingSort(int arr[], int n) {

    int max = findMax(arr, n);

    // Frequency array
    int count[max + 1];

    // Initialize count array with 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Compute prefix sums
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Output array
    int output[n];

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {

    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    countingSort(arr, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
