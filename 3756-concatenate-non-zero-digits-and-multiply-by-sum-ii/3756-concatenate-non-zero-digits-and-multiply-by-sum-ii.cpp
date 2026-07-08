class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<long long> sumD(n + 1, 0);
        vector<int> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            sumD[i + 1] = sumD[i] + d;
            if (d == 0) {
                cntN0[i + 1] = cntN0[i];
                p[i + 1] = p[i];
            } else {
                cntN0[i + 1] = cntN0[i] + 1;
                p[i + 1] = (p[i] * 10 + d) % MOD;
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            long long sd = sumD[r + 1] - sumD[l];
            int n0 = cntN0[r + 1] - cntN0[l];
            long long removed_prefix = (p[l] * pow10[n0]) % MOD;
            long long x = (p[r + 1] - removed_prefix + MOD) % MOD;
            ans.push_back((x * sd) % MOD);
        }
        return ans;
    }
};