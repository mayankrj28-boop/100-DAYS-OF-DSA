#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs1(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
        visited[node] = true;

        for (int v : adj[node]) {
            if (!visited[v]) {
                dfs1(v, adj, visited, st);
            }
        }

        st.push(node); // store by finish time
    }

    void dfs2(int node, vector<int> adjT[], vector<bool> &visited) {
        visited[node] = true;

        for (int v : adjT[node]) {
            if (!visited[v]) {
                dfs2(v, adjT, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1: fill stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }

        // Step 2: transpose graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            for (int v : adj[i]) {
                adjT[v].push_back(i);
            }
        }

        // Step 3: process stack
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                sccCount++;
                dfs2(node, adjT, visited);
            }
        }

        return sccCount;
    }
};
