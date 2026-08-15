class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;
        for (int x : nums) {
            total_xor ^= x;
            if (x != 0) has_nonzero = true;
        }
        if (total_xor != 0) return nums.size();
        if (has_nonzero) return nums.size() - 1;
        return 0;
    }
};