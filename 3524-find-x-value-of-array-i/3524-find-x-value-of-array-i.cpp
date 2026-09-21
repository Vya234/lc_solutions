class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int current_mod = num % k;
            next_dp[current_mod]++;
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_mod = (r * current_mod) % k;
                    next_dp[new_mod] += dp[r];
                }
            }
            for (int r = 0; r < k; ++r) ans[r] += next_dp[r];
            dp = move(next_dp);
        }
        return ans;
    }
};