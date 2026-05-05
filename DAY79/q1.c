#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

// Structure for adjacency list
struct Node {
    int v, w;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

// Min Heap structure
struct HeapNode {
    int vertex, dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* h, int idx) {
    while (idx && h->heap[idx].dist < h->heap[(idx - 1)/2].dist) {
        swap(&h->heap[idx], &h->heap[(idx - 1)/2]);
        idx = (idx - 1)/2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(struct MinHeap* h, int v, int dist) {
    h->heap[h->size].vertex = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop min
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Dijkstra
void dijkstra(int n, struct Node* adj[], int source) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[source] = 0;
    push(&heap, source, 0);

    while (heap.size > 0) {
        struct HeapNode curr = pop(&heap);
        int u = curr.vertex;
        int d = curr.dist;

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* temp1 = newNode(v, w);
        temp1->next = adj[u];
        adj[u] = temp1;

        struct Node* temp2 = newNode(u, w); // undirected
        temp2->next = adj[v];
        adj[v] = temp2;
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, adj, source);

    return 0;
}
