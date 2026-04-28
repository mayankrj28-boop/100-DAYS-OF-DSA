#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for level order construction
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* n) {
    queue[rear++] = n;
}

struct Node* dequeue() {
    return queue[front++];
}

// Function to find height
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (arr[0] == -1) {
        printf("0");
        return 0;
    }

    // Create root
    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    // Build tree from level order
    while (i < n && front < rear) {
        struct Node* current = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    printf("%d", height(root));

    return 0;
}
