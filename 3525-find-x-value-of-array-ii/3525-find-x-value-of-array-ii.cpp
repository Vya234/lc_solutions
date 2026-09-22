struct Node {
    int remain[5] = {0};
    int prod = 1;
};
class SegmentTree {
private:
    int n;
    int k;
    vector<Node> tree;
    Node merge(const Node& left, const Node& right) const {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for (int r = 0; r < k; ++r) {
            res.remain[r] = left.remain[r];
        }
        for (int r = 0; r < k; ++r) {
            int new_r = (r * left.prod) % k;
            res.remain[new_r] += right.remain[r];
        }
        return res;
    }
    void build(const vector<int>& nums, int cur, int l, int r) {
        if (l == r) {
            tree[cur].remain[nums[l] % k] = 1;
            tree[cur].prod = nums[l] % k;
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, 2 * cur + 1, l, mid);
        build(nums, 2 * cur + 2, mid + 1, r);
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }
    void update(int cur, int l, int r, int idx, int val) {
        if (l == r) {
            for (int i = 0; i < k; ++i) tree[cur].remain[i] = 0;
            tree[cur].remain[val % k] = 1;
            tree[cur].prod = val % k;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * cur + 1, l, mid, idx, val);
        } else {
            update(2 * cur + 2, mid + 1, r, idx, val);
        }
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }
    Node query(int cur, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) return tree[cur];
        int mid = l + (r - l) / 2;
        if (qr <= mid) return query(2 * cur + 1, l, mid, ql, qr);
        if (ql > mid) return query(2 * cur + 2, mid + 1, r, ql, qr);
        Node left_res = query(2 * cur + 1, l, mid, ql, qr);
        Node right_res = query(2 * cur + 2, mid + 1, r, ql, qr);
        return merge(left_res, right_res);
    }
public:
    SegmentTree(const std::vector<int>& nums, int k_val) 
        : n(nums.size()), k(k_val), tree(4 * nums.size()) {
        build(nums, 0, 0, n - 1);
    }
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
    Node query(int ql, int qr) const {
        return query(0, 0, n - 1, ql, qr);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree segTree(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            segTree.update(idx, val);
            Node resNode = segTree.query(start, nums.size() - 1);
            ans.push_back(resNode.remain[x]);
        }
        return ans;
    }
};