#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node to list
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find intersection point
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (!head1 || !head2)
        return NULL;

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1;  // either intersection node or NULL
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = append(head1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = append(head2, value);
    }

    // NOTE:
    // This code assumes lists are independent.
    // To test intersection manually, connect one list's node to another.

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
