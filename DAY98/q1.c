#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start;
    int end;
};

// Compare function for sorting
int compare(const void* a, const void* b) {

    return ((struct Interval*)a)->start -
           ((struct Interval*)b)->start;
}

// Function to merge intervals
void mergeIntervals(struct Interval arr[],
                    int n) {

    // Sort intervals by start time
    qsort(arr, n,
          sizeof(struct Interval), compare);

    // Temporary array for merged intervals
    struct Interval result[n];

    int index = 0;

    // Add first interval
    result[index] = arr[0];

    for (int i = 1; i < n; i++) {

        // Check overlap
        if (arr[i].start <= result[index].end) {

            // Merge intervals
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        }
        else {
            // No overlap
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ",
               result[i].start,
               result[i].end);
    }
}

int main() {

    struct Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(arr) /
            sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
