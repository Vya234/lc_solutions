class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }
        if (k == n) {
            int max_val = nums[0];
            for (int x : nums) {
                max_val = max(max_val, x);
            }
            return max_val;
        }
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};