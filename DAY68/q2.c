#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_set<char> uniqueChars;
        
        // Collect all unique characters
        for (auto &word : words) {
            for (char c : word) {
                uniqueChars.insert(c);
            }
        }

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        for (auto c : uniqueChars) {
            indegree[c] = 0;
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix issue
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Kahn's Algorithm
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string result;

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            result.push_back(node);

            for (char neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Cycle check
        if (result.size() != uniqueChars.size()) {
            return "";
        }

        return result;
    }
};
