#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// check empty
int empty()
{
    if (front == -1)
        return 1;
    return 0;
}

// check full
int full()
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}

// push front
void push_front(int x)
{
    if (full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (empty())
    {
        front = rear = 0;
    }
    else if (front > 0)
    {
        front--;
    }
    else
    {
        printf("No space at front\n");
        return;
    }

    deque[front] = x;
}

// push back
void push_back(int x)
{
    if (full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (empty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
}

// pop front
void pop_front()
{
    if (empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// pop back
void pop_back()
{
    if (empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

// front element
void get_front()
{
    if (empty())
        printf("Deque Empty\n");
    else
        printf("Front = %d\n", deque[front]);
}

// back element
void get_back()
{
    if (empty())
        printf("Deque Empty\n");
    else
        printf("Back = %d\n", deque[rear]);
}

// size
void size()
{
    if (empty())
        printf("Size = 0\n");
    else
        printf("Size = %d\n", rear - front + 1);
}

// display
void display()
{
    if (empty())
    {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    push_back(10);
    push_front(5);
    push_back(20);

    display();

    get_front();
    get_back();

    pop_front();
    display();

    size();

    return 0;
}
