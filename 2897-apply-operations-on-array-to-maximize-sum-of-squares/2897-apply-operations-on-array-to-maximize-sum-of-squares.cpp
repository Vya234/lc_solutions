class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bit_count(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bit_count[i]++;
                }
            }
        }
        long long total_sum = 0;
        for (int step = 0; step < k; ++step) {
            long long val = 0;
            for (int i = 0; i < 30; ++i) {
                if (bit_count[i] > 0) {
                    val |= (1LL << i);
                    bit_count[i]--;
                }
            }
            total_sum = (total_sum + (val % MOD) * (val % MOD)) % MOD;
        }
        return total_sum;
    }
};