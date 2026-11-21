
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        vector<int> path[26];
        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            path[c].push_back(u);
            for (int v : adj[u]) dfs(v);
            int newParent = parent[u];
            if (path[c].size() > 1) {
                newParent = path[c][path[c].size() - 2];
            }
            if (newParent != -1) {
                ans[newParent] += ans[u];
            }
            path[c].pop_back();
        };
        dfs(0);
        return ans;
    }
};
