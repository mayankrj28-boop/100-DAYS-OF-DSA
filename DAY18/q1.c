#include <stdio.h>

// function to reverse array
void reverse(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int n, k;

    // input size
    scanf("%d", &n);

    int arr[n];

    // input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // input k
    scanf("%d", &k);

    // handle k > n
    k = k % n;

    // rotation steps
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

    // output rotated array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
