#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x)
{
    if (size == MAX)
        return;

    pq[size] = x;
    size++;
}

// Find index of smallest element
int findMinIndex()
{
    if (size == 0)
        return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    return minIndex;
}

// Delete highest priority (smallest)
int deletePQ()
{
    if (size == 0)
        return -1;

    int minIndex = findMinIndex();
    int value = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;

    return value;
}

// Peek highest priority
int peek()
{
    if (size == 0)
        return -1;

    int minIndex = findMinIndex();
    return pq[minIndex];
}

int main()
{
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            printf("%d\n", deletePQ());
        }
        else if (strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}
