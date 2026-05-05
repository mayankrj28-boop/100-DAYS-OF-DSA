#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(sizeof(int) * graphSize);

    // -1 means uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Check all components
    for (int i = 0; i < graphSize; i++) {
        if (color[i] != -1) continue;

        // BFS queue
        int queue[graphSize];
        int front = 0, rear = 0;

        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                // If not colored
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // If same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    free(color);
                    return false;
                }
            }
        }
    }

    free(color);
    return true;
}
