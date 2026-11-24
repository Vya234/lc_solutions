class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxEl = 0, totalLcm = 1;
        for (int x : nums) {
            maxEl = max(maxEl, x);
            totalLcm = lcm(totalLcm, x);
        }
        long long limit = 1LL*totalLcm*maxEl;
        int n = nums.size(), ans = 2;
        for (int i=0; i<n; ++i) {
            long long p=1;
            int g=0, l=1;
            for (int j=i; j<n; ++j) {
                p *= nums[j];
                if (p > limit) break;
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if (p == 1LL*g*l) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};