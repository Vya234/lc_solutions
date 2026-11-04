class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> window_cost(n, 0);
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;
        
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                long long val = *it;
                low.erase(it);
                sum_low -= val;
                high.insert(val);
                sum_high += val;
            }
            while (low.size() < high.size()) {
                auto it = high.begin();
                long long val = *it;
                high.erase(it);
                sum_high -= val;
                low.insert(val);
                sum_low += val;
            }
        };
        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sum_low += val;
            } else {
                high.insert(val);
                sum_high += val;
            }
            balance();
        };
        auto remove = [&](long long val) {
            auto it = low.find(val);
            if (it != low.end()) {
                low.erase(it);
                sum_low -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sum_high -= val;
            }
            balance();
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *low.rbegin();
                long long current_cost = (median * low.size() - sum_low) + (sum_high - median * high.size());
                window_cost[i] = current_cost;
            }
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + window_cost[i - 1]);
            }
        }
        return dp[n][k];
    }
};