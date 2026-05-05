#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} Pair;

Pair pq[MAX];
int size = 0;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(Pair p) {
    pq[++size] = p;
    int i = size;

    while (i > 1 && pq[i].dist < pq[i/2].dist) {
        swap(&pq[i], &pq[i/2]);
        i /= 2;
    }
}

Pair pop() {
    Pair top = pq[1];
    pq[1] = pq[size--];

    int i = 1;
    while (2*i <= size) {
        int child = 2*i;
        if (child+1 <= size && pq[child+1].dist < pq[child].dist)
            child++;

        if (pq[i].dist > pq[child].dist) {
            swap(&pq[i], &pq[child]);
            i = child;
        } else break;
    }

    return top;
}

int isEmpty() {
    return size == 0;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push((Pair){src, 0});

    while (!isEmpty()) {
        Pair p = pop();
        int u = p.node;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                push((Pair){v, dist[v]});
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int V = 5;
    int graph[MAX][MAX] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    dijkstra(graph, V, 0);
    return 0;
}
