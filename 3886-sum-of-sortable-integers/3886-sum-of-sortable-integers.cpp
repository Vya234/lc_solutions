class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        auto isSortable = [&](int k) -> bool {
            int numBlocks = n / k;
            int prevBlockMax = -1;
            for (int b = 0; b < numBlocks; ++b) {
                int start = b * k;
                int end = start + k;
                int descents = 0;
                for (int i = start; i < end - 1; ++i) {
                    if (nums[i] > nums[i + 1]) descents++;
                }
                if (nums[end - 1] > nums[start]) descents++;
                if (descents > 1) return false;
                int minVal = nums[start], maxVal = nums[start];
                for (int i = start; i < end; ++i) {
                    minVal = min(minVal, nums[i]);
                    maxVal = max(maxVal, nums[i]);
                }
                if (b > 0 && prevBlockMax > minVal) return false;
                prevBlockMax = maxVal;
            }
            return true;
        };
        int totalSum = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(k)) totalSum += k;
            }
        }
        return totalSum;
    }
};