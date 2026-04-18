#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;


// prototypes
KthLargest* kthLargestCreate(int k, int* nums, int numsSize);
int kthLargestAdd(KthLargest* obj, int val);
void kthLargestFree(KthLargest* obj);

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


// heapify up
void heapUp(KthLargest* obj, int i)
{
    while (i > 0)
    {
        int p = (i - 1) / 2;

        if (obj->heap[p] <= obj->heap[i])
            break;

        swap(&obj->heap[p], &obj->heap[i]);
        i = p;
    }
}


// heapify down
void heapDown(KthLargest* obj, int i)
{
    while (1)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < obj->size && obj->heap[l] < obj->heap[s])
            s = l;

        if (r < obj->size && obj->heap[r] < obj->heap[s])
            s = r;

        if (s == i)
            break;

        swap(&obj->heap[i], &obj->heap[s]);
        i = s;
    }
}


KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
{
    KthLargest* obj = malloc(sizeof(KthLargest));

    obj->heap = malloc((k + 1) * sizeof(int));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++)
    {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}


int kthLargestAdd(KthLargest* obj, int val)
{
    if (obj->size < obj->k)
    {
        obj->heap[obj->size] = val;
        heapUp(obj, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0])
    {
        obj->heap[0] = val;
        heapDown(obj, 0);
    }

    if (obj->size < obj->k)
        return -1;

    return obj->heap[0];
}


void kthLargestFree(KthLargest* obj)
{
    free(obj->heap);
    free(obj);
}
