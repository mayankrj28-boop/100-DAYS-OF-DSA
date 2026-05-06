/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and column sizes array
 * must be malloced.
 */

#include <stdlib.h>

// Compare function for sorting
int compare(const void* a, const void* b) {

    int* x = *(int**)a;
    int* y = *(int**)b;

    return x[0] - y[0];
}

int** merge(int** intervals,
            int intervalsSize,
            int* intervalsColSize,
            int* returnSize,
            int** returnColumnSizes) {

    // Sort intervals by start time
    qsort(intervals,
          intervalsSize,
          sizeof(int*),
          compare);

    // Result array
    int** result =
        (int**)malloc(intervalsSize *
                      sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(intervalsSize *
                     sizeof(int));

    int index = 0;

    // First interval
    result[index] =
        (int*)malloc(2 * sizeof(int));

    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];

    (*returnColumnSizes)[index] = 2;

    // Traverse remaining intervals
    for (int i = 1; i < intervalsSize; i++) {

        // Overlapping interval
        if (intervals[i][0] <=
            result[index][1]) {

            // Update ending time
            if (intervals[i][1] >
                result[index][1]) {

                result[index][1] =
                    intervals[i][1];
            }
        }
        else {

            // New interval
            index++;

            result[index] =
                (int*)malloc(2 * sizeof(int));

            result[index][0] =
                intervals[i][0];

            result[index][1] =
                intervals[i][1];

            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;

    return result;
}
