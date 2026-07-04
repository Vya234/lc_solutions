class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<bool> vis;
    int ans = INT_MAX;
    void dfs(int u) {
        vis[u] = true;
        for (auto &[v, wt] : adj[u]) {
            ans = min(ans, wt);
            if (!vis[v]) {
                dfs(v);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        vis.assign(n + 1, false);
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        dfs(1);
        return ans;

    }
};