#include <stdbool.h>
#include <stdlib.h>

bool dfs(int node, int numCourses, int **adj, bool *visited, bool *recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < numCourses; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, numCourses, adj, visited, recStack))
                    return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Create adjacency matrix
    int **adj = (int **)malloc(numCourses * sizeof(int *));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int *)calloc(numCourses, sizeof(int));
    }

    // Build graph: bi → ai
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][a] = 1;
    }

    bool *visited = (bool *)calloc(numCourses, sizeof(bool));
    bool *recStack = (bool *)calloc(numCourses, sizeof(bool));

    // Check cycle
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, numCourses, adj, visited, recStack))
                return false;
        }
    }

    return true;
}
