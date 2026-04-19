#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = -1, rear = -1;
int top = -1;


// enqueue
void enqueue(int x)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}


// dequeue
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}


// push stack
void push(int x)
{
    if (top == MAX - 1)
        return;

    stack[++top] = x;
}


// pop stack
int pop()
{
    if (top == -1)
        return -1;

    return stack[top--];
}


int main()
{
    int n, x;

    scanf("%d", &n);

    // input queue
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // queue → stack
    while (front <= rear)
    {
        push(dequeue());
    }

    // stack → queue
    front = 0;
    rear = -1;

    while (top != -1)
    {
        enqueue(pop());
    }

    // print queue
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
