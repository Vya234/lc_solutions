class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;
        vector<long long> gcdCnt(mx + 1, 0);
        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;
            for (int multiple = g; multiple <= mx; multiple += g) cnt += freq[multiple];
            gcdCnt[g] = cnt * (cnt - 1) / 2;
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                gcdCnt[g] -= gcdCnt[multiple];
        }
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) prefix[i] = prefix[i - 1] + gcdCnt[i];
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;  
    }
};