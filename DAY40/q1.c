#include <stdio.h>

// Function to heapify subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;        // root
    int left = 2*i + 1;
    int right = 2*i + 2;

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    heapSort(arr, n);

    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
