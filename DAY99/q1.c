#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int position;
    int speed;
};

// Compare function for sorting
// Sort by position in descending order
int compare(const void* a, const void* b) {

    return ((struct Car*)b)->position -
           ((struct Car*)a)->position;
}

// Function to count car fleets
int carFleet(int target,
             int position[],
             int speed[],
             int n) {

    struct Car cars[n];

    // Store cars data
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by position descending
    qsort(cars, n,
          sizeof(struct Car), compare);

    int fleets = 0;

    double prevTime = 0;

    // Traverse from nearest car to target
    for (int i = 0; i < n; i++) {

        // Time to reach target
        double time =
            (double)(target - cars[i].position)
            / cars[i].speed;

        // New fleet formed
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}

int main() {

    int target = 12;

    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};

    int n = sizeof(position) /
            sizeof(position[0]);

    printf("Number of Car Fleets = %d",
           carFleet(target,
                    position,
                    speed,
                    n));

    return 0;
}
