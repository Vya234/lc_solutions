class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int, int>> valid_intervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            int left = first[i];
            int right = last[i];
            bool isValid = true;
            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                left = min(left, first[c]);
                right = max(right, last[c]);
                if (left < first[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                valid_intervals.push_back({right, left}); 
            }
        }
        sort(valid_intervals.begin(), valid_intervals.end());
        vector<string> result;
        int prev_end = -1;
        for (auto& interval : valid_intervals) {
            int right = interval.first;
            int left = interval.second;
            if (left > prev_end) {
                result.push_back(s.substr(left, right - left + 1));
                prev_end = right;
            }
        }
        return result;
    }
};