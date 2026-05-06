#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (currentPages + arr[i] <= maxPages) {
            currentPages += arr[i];
        } else {
            students++;
            currentPages = arr[i];

            if (students > m) {
                return 0; // false
            }
        }
    }
    return 1; // true
}

// Function to allocate books
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int maxVal = arr[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        sum += arr[i];
    }

    int low = maxVal;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // increase
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}
