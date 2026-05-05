#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Simple hashmap using arrays (for demo)
    // Assuming sum range is limited
    int map[20001];  // for sums from -10000 to 10000
    for (int i = 0; i < 20001; i++) map[i] = -2;

    int offset = 10000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (map[sum + offset] != -2) {
            int prevIndex = map[sum + offset];
            if (i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            map[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}
