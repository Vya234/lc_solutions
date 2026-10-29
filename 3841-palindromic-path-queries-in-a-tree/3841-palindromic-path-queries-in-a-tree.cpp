class Solution {
    int n, timer, LOGN = 18;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    string current_s;

    void addBIT(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] ^= val;
    }

    void updateRangeBIT(int l, int r, int val) {
        addBIT(l, val);
        addBIT(r + 1, val);
    }

    int queryBIT(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    }

    void dfs(int u, int p, int d, int current_path_mask) {
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOGN; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        int path_mask = current_path_mask ^ (1 << (current_s[u] - 'a'));
        updateRangeBIT(tin[u], tin[u], path_mask);

        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1, path_mask);
        }
        tout[u] = timer;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOGN - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
        }
        if (u == v) return u;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->current_s = s;
        this->timer = 0;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOGN, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0, 0, 0);

        vector<bool> result;

        for (auto& q_str : queries) {
            stringstream ss(q_str);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                if (current_s[u] == c) continue;

                int diff_mask = (1 << (current_s[u] - 'a')) ^ (1 << (c - 'a'));
                current_s[u] = c;
                updateRangeBIT(tin[u], tout[u], diff_mask);

            } else {
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);
                int path_mask = queryBIT(tin[u]) ^ queryBIT(tin[v]) ^ (1 << (current_s[lca] - 'a'));

                result.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return result;
    }
};