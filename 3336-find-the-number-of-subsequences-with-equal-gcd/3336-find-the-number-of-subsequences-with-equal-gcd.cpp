class Solution {
private:
    int MOD = 1e9 + 7;
    int memo[201][201][201];
    int maxVal;
    int getGCD(int a, int b) {
        return b == 0 ? a : std::gcd(a, b);
    }
    int solve(int i, int x, int y, const vector<int>& nums) {
            if (i == nums.size()) {
            return (x > 0 && x == y) ? 1 : 0;
        }
        if (memo[i][x][y] != -1) {
            return memo[i][x][y];
        }
        long long ans = solve(i + 1, x, y, nums);
        int nextX = (x == 0) ? nums[i] : getGCD(x, nums[i]);
        ans = (ans + solve(i + 1, nextX, y, nums)) % MOD;
        int nextY = (y == 0) ? nums[i] : getGCD(y, nums[i]);
        ans = (ans + solve(i + 1, x, nextY, nums)) % MOD;
        return memo[i][x][y] = ans;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        maxVal = *max_element(nums.begin(), nums.end());
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};