class Solution {
public:
    vector<int> bit;
    void update(int idx, int val, int n) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int OFFSET = n + 1;
        int SIZE = 2 * n + 2;
        bit.assign(SIZE + 1, 0);
        long long ans = 0;
        int prefix = 0;
        update(OFFSET, 1, SIZE);
        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;
            ans += query(prefix - 1 + OFFSET);
            update(prefix + OFFSET, 1, SIZE);
        }
        return ans;
    }
};