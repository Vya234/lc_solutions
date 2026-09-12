class Solution {
    struct Interval {
        long long l, r, weight;
        int orig_idx;
    };
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {(long long)intervals[i][0], (long long)intervals[i][1], (long long)intervals[i][2], i};
        }
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.orig_idx < b.orig_idx;
        });
        vector<int> next_idx(n);
        for (int i = 0; i < n; ++i) {
            int low = i + 1, high = n, ans = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].l > arr[i].r) {
                    ans = mid;
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            next_idx[i] = ans;
        }
        using Result = pair<long long, vector<int>>;
        vector<vector<Result>> dp(n + 1, vector<Result>(5, {0LL, {}}));
        auto isBetter = [](const Result& a, const Result& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; 
        };
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                Result best = dp[i + 1][k];
                int nxt = next_idx[i];
                long long take_weight = arr[i].weight + dp[nxt][k - 1].first;
                vector<int> take_indices = {arr[i].orig_idx};
                take_indices.insert(take_indices.end(), dp[nxt][k - 1].second.begin(), dp[nxt][k - 1].second.end());
                sort(take_indices.begin(), take_indices.end());
                Result take_res = {take_weight, take_indices};
                if (isBetter(take_res, best)) {
                    best = take_res;
                }
                dp[i][k] = best;
            }
        }
        return dp[0][4].second;
    }
};