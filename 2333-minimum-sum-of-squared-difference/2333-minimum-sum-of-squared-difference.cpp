class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        const int MAX_DIFF = 100000;
        vector<int> freq(MAX_DIFF + 1, 0);
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
        }
        for (int d = MAX_DIFF; d > 0 && k > 0; --d) {
            if (freq[d] == 0) continue;
            long long count = min((long long)freq[d], k);
            freq[d] -= count;
            freq[d - 1] += count;
            k -= count;
        }
        long long ans = 0;
        for (long long d = 1; d <= MAX_DIFF; ++d) {
            if (freq[d] > 0) {
                ans += (long long)freq[d] * d * d;
            }
        }
        return ans;
    }
};