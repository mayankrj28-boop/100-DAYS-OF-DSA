#include <stdio.h>
#include <stdlib.h>

void dfs(int** adj, int* adjSize, int* visited, int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(adj, adjSize, visited, neighbor);
        }
    }
}

int main() {
    int n, m;

    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    // Allocate adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    // Temporary storage for edges
    int u, v;

    // First pass: count degrees
    int* degree = (int*)calloc(n, sizeof(int));
    int edges[m][2];

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        degree[u]++;
        degree[v]++;   // remove if directed graph
    }

    // Allocate memory for adjacency lists
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Fill adjacency list
    for (int i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;   // remove if directed
    }

    int s;
    scanf("%d", &s);   // starting vertex

    int* visited = (int*)calloc(n, sizeof(int));

    // Perform DFS
    dfs(adj, adjSize, visited, s);

    return 0;
}
