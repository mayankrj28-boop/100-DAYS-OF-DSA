#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer;

    void dfs(int u, vector<int> adj[], vector<int> &disc, vector<int> &low,
             vector<int> &parent, vector<bool> &visited, vector<bool> &ap) {

        visited[u] = true;
        disc[u] = low[u] = ++timer;

        int children = 0;

        for (int v : adj[u]) {

            if (!visited[v]) {
                children++;
                parent[v] = u;

                dfs(v, adj, disc, low, parent, visited, ap);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Condition 1: root node
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                // Condition 2: non-root
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {

        vector<int> disc(V), low(V), parent(V, -1);
        vector<bool> visited(V, false), ap(V, false);

        timer = 0;

        // Run DFS
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, disc, low, parent, visited, ap);
            }
        }

        // Collect result
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i])
                result.push_back(i);
        }

        if (result.empty())
            return {-1};

        sort(result.begin(), result.end());
        return result;
    }
};
