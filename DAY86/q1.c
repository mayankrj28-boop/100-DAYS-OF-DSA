#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // To avoid overflow, use long long
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;  // exact square root
        } 
        else if (square < n) {
            ans = mid;   // store possible answer
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return ans;  // integer square root
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}
