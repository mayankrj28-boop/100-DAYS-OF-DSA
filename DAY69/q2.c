#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int graph[101][101];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Fill edges
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[101];
    int visited[101] = {0};

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;

    // Dijkstra (O(n^2))
    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find min distance node not visited
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;

        // Relax edges
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Find answer
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}
