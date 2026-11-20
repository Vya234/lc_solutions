class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back();
        vector<int> dp(maxVal + 2, 0);
        int ans = 1;
        for (int num : nums) {
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num - 1] + 1;
            ans = max({ans, dp[num], dp[num + 1]});
        }
        return ans;
    }
};