struct Node {
    int max_len = 0;
    int prefix_len = 0;
    int suffix_len = 0;
    char prefix_char = ' ';
    char suffix_char = ' ';
};
class SegmentTree {
    int n;
    vector<Node> tree;
    Node merge(const Node& left, const Node& right, int left_len, int right_len) {
        Node res;
        res.prefix_char = left.prefix_char;
        res.suffix_char = right.suffix_char;
        res.prefix_len = left.prefix_len;
        if (left.prefix_len == left_len && left.prefix_char == right.prefix_char) {
            res.prefix_len += right.prefix_len;
        }
        res.suffix_len = right.suffix_len;
        if (right.suffix_len == right_len && right.suffix_char == left.suffix_char) {
            res.suffix_len += left.suffix_len;
        }
        res.max_len = max(left.max_len, right.max_len);
        if (left.suffix_char == right.prefix_char) {
            res.max_len = max(res.max_len, left.suffix_len + right.prefix_len);
        }
        return res;
    }
    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }
public:
    SegmentTree(const string& s) : n(s.length()), tree(4 * s.length()) {
        build(s, 1, 0, n - 1);
    }
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }
    int getMax() {
        return tree[1].max_len;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        SegmentTree st(s);
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            st.update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }
        return ans;
    }
};