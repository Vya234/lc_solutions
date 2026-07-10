class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; i++) {
            pairs.emplace_back(nums[i], i);
        }
        sort(pairs.begin(), pairs.end());
        int m = 20; 
        vector<vector<int>> f(n, vector<int>(m));
        int r = n - 1;
        for (int l = n - 1; l >= 0; l--) {
            while (pairs[r].first - pairs[l].first > maxDiff) {
                r--;
            }
            int i = pairs[l].second;
            int j = pairs[r].second;
            f[i][0] = j; 
            for (int k = 1; k < m; k++) {
                f[i][k] = f[f[i][k - 1]][k - 1];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            if (nums[i] > nums[j]) {
                swap(i, j);
            }
            if (i == j) {
                ans.push_back(0);
                continue;
            }
            if (nums[i] == nums[j]) {
                ans.push_back(1);
                continue;
            }
            int steps = 0;
            for (int k = m - 1; k >= 0; k--) {
                if (nums[f[i][k]] < nums[j]) {
                    steps |= (1 << k);
                    i = f[i][k];
                }
            }
            if (nums[f[i][0]] < nums[j]) {
                ans.push_back(-1); 
            } else {
                ans.push_back(steps + 1);
            }
        }
        return ans;
    }
};