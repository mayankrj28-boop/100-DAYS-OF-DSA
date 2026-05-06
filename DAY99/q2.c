/**
 * Note: The returned value should be an integer.
 */

#include <stdlib.h>

// Structure for car
struct Car {
    int position;
    int speed;
};

// Compare function
// Sort cars by position descending
int compare(const void* a, const void* b) {

    return ((struct Car*)b)->position -
           ((struct Car*)a)->position;
}

int carFleet(int target,
             int* position,
             int positionSize,
             int* speed,
             int speedSize) {

    struct Car cars[positionSize];

    // Store car data
    for (int i = 0; i < positionSize; i++) {

        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position
    qsort(cars,
          positionSize,
          sizeof(struct Car),
          compare);

    int fleets = 0;

    double prevTime = 0;

    // Traverse cars
    for (int i = 0; i < positionSize; i++) {

        // Time to reach target
        double currTime =
            (double)(target -
                     cars[i].position)
            / cars[i].speed;

        // New fleet formed
        if (currTime > prevTime) {

            fleets++;
            prevTime = currTime;
        }
    }

    return fleets;
}
