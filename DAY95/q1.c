#include <stdio.h>
#include <stdlib.h>

// Structure for bucket nodes
struct Node {
    float data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node in sorted order inside bucket
void insertSorted(struct Node** head, float value) {

    struct Node* newNode = createNode(value);

    // Insert at beginning
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Find correct position
    struct Node* current = *head;

    while (current->next != NULL &&
           current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {

    // Create buckets
    struct Node* buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {

        int index = arr[i] * n;

        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets back into array
    int k = 0;

    for (int i = 0; i < n; i++) {

        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {

    float arr[] = {0.42, 0.32, 0.23, 0.52,
                   0.25, 0.47, 0.51};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n\nSorted Array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
