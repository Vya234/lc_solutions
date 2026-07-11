class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[node] = true;
        nodeCount++;
        edgeCount += adj[node].size(); 
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodeCount, edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int nodeCount = 0;
                int edgeCount = 0;
                dfs(i, adj, visited, nodeCount, edgeCount);
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeComponents++;
                }
            }
        }   
        return completeComponents;
    }
};