class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        sort(squares.begin(), squares.end());
        long long score = 0;
        int num_sub = n / 2;          
        int num_add = (n + 1) / 2;     
        for (int i = 0; i < num_sub; ++i) {
            score -= squares[i];
        }
        for (int i = num_sub; i < n; ++i) {
            score += squares[i];
        }
        return score;
    }
};