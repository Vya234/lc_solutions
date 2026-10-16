class Solution {
private:
    static const int MOD = 1e9 + 7;
    vector<long long> tree_sum, tree_sq, lazy;
    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        long long val = lazy[node];
        int mid = start + (end - start) / 2;
        int left = 2 * node, right = 2 * node + 1;
        int len_l = mid - start + 1;
        int len_r = end - mid;

        tree_sq[left] = (tree_sq[left] + 2 * val * tree_sum[left] % MOD + val * val % MOD * len_l) % MOD;
        tree_sum[left] = (tree_sum[left] + val * len_l) % MOD;
        lazy[left] = (lazy[left] + val) % MOD;

        tree_sq[right] = (tree_sq[right] + 2 * val * tree_sum[right] % MOD + val * val % MOD * len_r) % MOD;
        tree_sum[right] = (tree_sum[right] + val * len_r) % MOD;
        lazy[right] = (lazy[right] + val) % MOD;

        lazy[node] = 0;
    }
    void update(int node, int start, int end, int l, int r, long long val) {
        if (l <= start && end <= r) {
            int len = end - start + 1;
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] % MOD + val * val % MOD * len) % MOD;
            tree_sum[node] = (tree_sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, start, end);
        int mid = start + (end - start) / 2;
        if (l <= mid) update(2 * node, start, mid, l, r, val);
        if (r > mid) update(2 * node + 1, mid + 1, end, l, r, val);

        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_ans = 0;

        for (int j = 0; j < n; ++j) {
            int prev_idx = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            update(1, 0, n - 1, prev_idx + 1, j, 1);
            total_ans = (total_ans + tree_sq[1]) % MOD;
            last_pos[nums[j]] = j;
        }
        return total_ans;
    }
};