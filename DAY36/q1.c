#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (front == NULL) {
        front = rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        return;
    }

    struct node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display queue
void display() {
    if (front == NULL)
        return;

    struct node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
