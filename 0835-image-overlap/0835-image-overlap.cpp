class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) v1.push_back({r, c});
                if (img2[r][c] == 1) v2.push_back({r, c});
            }
        }
        map<pair<int, int>, int> shift_count;
        int max_overlap = 0;
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                pair<int, int> shift = {p2.first - p1.first, p2.second - p1.second};
                shift_count[shift]++;
                max_overlap = max(max_overlap, shift_count[shift]);
            }
        }
        return max_overlap;
    }
};