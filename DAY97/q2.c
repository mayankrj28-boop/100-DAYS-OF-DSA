#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find minimum meeting rooms
int minRooms(int start[], int end[], int n) {

    // Sort start and end times
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0;
    int maxRooms = 0;

    int i = 0; // Pointer for start[]
    int j = 0; // Pointer for end[]

    while (i < n && j < n) {

        // New meeting starts before previous ends
        if (start[i] < end[j]) {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else {
            // Room becomes free
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {

    int start[] = {2, 9, 6};
    int end[] = {4, 12, 10};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum Rooms Required = %d",
           minRooms(start, end, n));

    return 0;
}
