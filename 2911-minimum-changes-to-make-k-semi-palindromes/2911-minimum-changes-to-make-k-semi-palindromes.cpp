class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int offset = 0; offset < d; ++offset) {
                        int l = i + offset;
                        int r = j - d + 1 + offset;
                        while (l < r) {
                            if (s[l] != s[r]) {
                                ++changes;
                            }
                            l += d;
                            r -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) { 
                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (dp[m][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], dp[m][p - 1] + cost[m][i - 1]);
                    }
                }
            }
        } 
        return dp[n][k];
    }
};