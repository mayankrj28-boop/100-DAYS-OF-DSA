#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Using array as hash (range assumption)
    int hash[20001] = {0}; 
    int offset = 10000;  // To handle negative sums

    hash[offset] = 1;  // Prefix sum 0 occurs once initially

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(hash[prefix_sum + offset] > 0) {
            count += hash[prefix_sum + offset];
        }

        hash[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
