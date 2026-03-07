#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int left, right, temp;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    left = 0;
    right = n - 1;

    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
