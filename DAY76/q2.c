struct Node* map[101];

struct Node* dfs(struct Node* node) {
    if(node == NULL)
        return NULL;
    
    if(map[node->val] != NULL)
        return map[node->val];
    
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    
    map[node->val] = clone;
    
    for(int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }
    
    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    for(int i = 0; i <= 100; i++)
        map[i] = NULL;
    
    return dfs(s);
}
