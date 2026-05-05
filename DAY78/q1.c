#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];  
    int key[MAX];     
    bool mstSet[MAX]; 

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;     // Start from node 1
    parent[1] = -1;

    for (int count = 1; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 2; i <= n; i++) {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    printf("%d\n", primMST());

    return 0;
}
