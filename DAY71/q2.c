#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int manhattan(int *p1, int *p2) {
    return absVal(p1[0] - p2[0]) + absVal(p1[1] - p2[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    bool visited[1000] = {false};
    int minDist[1000];

    // Initialize distances
    for (int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < pointsSize; i++) {
        int u = -1;

        // Pick minimum distance unvisited node
        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u], points[v]);
                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    return totalCost;
}
