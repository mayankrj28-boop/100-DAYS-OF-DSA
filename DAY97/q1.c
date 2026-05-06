#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
struct Interval {
    int start;
    int end;
};

// Compare function for sorting by start time
int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start -
           ((struct Interval*)b)->start;
}

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify
void heapify(int heap[], int size, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size &&
        heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < size &&
        heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Insert into Min Heap
void insertHeap(int heap[], int* size, int value) {

    int i = (*size)++;
    heap[i] = value;

    while (i != 0 &&
           heap[(i - 1) / 2] > heap[i]) {

        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove minimum element
void removeMin(int heap[], int* size) {

    heap[0] = heap[--(*size)];

    heapify(heap, *size, 0);
}

// Function to find minimum meeting rooms
int minMeetingRooms(struct Interval intervals[],
                    int n) {

    if (n == 0)
        return 0;

    // Sort meetings by start time
    qsort(intervals, n,
          sizeof(struct Interval), compare);

    // Min heap for end times
    int heap[n];
    int heapSize = 0;

    // Add first meeting end time
    insertHeap(heap, &heapSize,
               intervals[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {

        // If room becomes free
        if (intervals[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        // Allocate room
        insertHeap(heap, &heapSize,
                   intervals[i].end);

        // Update maximum rooms
        if (heapSize > maxRooms) {
            maxRooms = heapSize;
        }
    }

    return maxRooms;
}

int main() {

    struct Interval meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) /
            sizeof(meetings[0]);

    printf("Minimum Meeting Rooms = %d",
           minMeetingRooms(meetings, n));

    return 0;
}
