class Solution {
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (getDigitSum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};