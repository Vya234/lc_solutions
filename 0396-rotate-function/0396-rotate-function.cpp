class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long totalSum = 0;
        long long f = 0;
        int n = nums.size();

        // Compute total sum and F(0)
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        // Compute F(1), F(2), ..., F(n-1)
        for (int k = 1; k < n; k++) {
            f = f + totalSum - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return (int)ans;
    }
};