class Group {
public:
    int start;
    int length;

    Group(int s, int l) : start(s), length(l) {}
};
class SparseTable {
public:
    vector<vector<int>> st;
    SparseTable() {}
    SparseTable(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            st = {{0}};
            return;
        }
        int k = 32 - __builtin_clz(n); 
        st.assign(k, vector<int>(n, 0));
        st[0] = nums;
        int j = 1;
        while ((1 << j) <= n) {
            int i = 0;
            while (i + (1 << j) <= n) {
                st[j][i] = max(
                    st[j - 1][i],
                    st[j - 1][i + (1 << (j - 1))]
                );
                i++;
            }
            j++;
        }
    }
    int query(int l, int r) {
        int range_len = r - l + 1;
        int k = 31 - __builtin_clz(range_len); 
        return max(
            st[k][l],
            st[k][r - (1 << k) + 1]
        );
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        auto [zero_groups, zero_idx] = get_zero_groups(s);

        if (zero_groups.empty()) {
            return vector<int>(queries.size(), ones);
        }
        vector<int> merge_lengths;
        for (size_t i = 0; i < zero_groups.size() - 1; ++i) {
            merge_lengths.push_back(
                zero_groups[i].length + zero_groups[i + 1].length
            );
        }
        SparseTable st(merge_lengths);
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int left = (zero_idx[l] == -1) 
                ? -1 
                : (zero_groups[zero_idx[l]].length - (l - zero_groups[zero_idx[l]].start));
            int right = (zero_idx[r] == -1) 
                ? -1 
                : (r - zero_groups[zero_idx[r]].start + 1);
            int start_adj = zero_idx[l] + 1;
            int end_adj = (s[r] == '1') 
                ? zero_idx[r] - 1 
                : zero_idx[r] - 2;
            int best = ones;
            if (s[l] == '0' && s[r] == '0' && zero_idx[l] + 1 == zero_idx[r]) {
                best = max(best, ones + left + right);
            }
            else if (start_adj <= end_adj && !merge_lengths.empty()) {
                best = max(best, ones + st.query(start_adj, end_adj));
            }
            int limit = (s[r] == '1') 
                ? zero_idx[r] 
                : zero_idx[r] - 1;
            if (s[l] == '0' && zero_idx[l] + 1 <= limit) {
                best = max(
                    best,
                    ones + left + zero_groups[zero_idx[l] + 1].length
                );
            }
            if (s[r] == '0' && zero_idx[l] < zero_idx[r] - 1) {
                best = max(
                    best,
                    ones + right + zero_groups[zero_idx[r] - 1].length
                );
            }
            ans.push_back(best);
        }
        return ans;
    }
private:
    pair<vector<Group>, vector<int>> get_zero_groups(const string& s) {
        vector<Group> groups;
        vector<int> idx;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    groups.back().length += 1;
                } else {
                    groups.push_back(Group(i, 1));
                }
            }
            idx.push_back((int)groups.size() - 1);
        }
        return {groups, idx};
    }
};