#include <stdio.h>

// Function to check if we can ship within given days
int canShip(int* weights, int size, int days, int capacity) {
    int usedDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < size; i++) {
        if (currentLoad + weights[i] <= capacity) {
            currentLoad += weights[i];
        } else {
            usedDays++;
            currentLoad = weights[i];

            if (usedDays > days) {
                return 0; // not possible
            }
        }
    }
    return 1; // possible
}

// Main function (LeetCode format)
int shipWithinDays(int* weights, int weightsSize, int days) {
    int maxVal = weights[0], sum = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > maxVal)
            maxVal = weights[i];
        sum += weights[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller capacity
        } else {
            low = mid + 1;   // increase capacity
        }
    }

    return ans;
}
