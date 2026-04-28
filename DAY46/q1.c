#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// queue for level order
struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// level order traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);

        if (temp->right)
            enqueue(temp->right);
    }
}

int main() {
    int n, val;
    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node* nodes[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(val);
    }

    // link children
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    levelOrder(nodes[0]);

    return 0;
}
