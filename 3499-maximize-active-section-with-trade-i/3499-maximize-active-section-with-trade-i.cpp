class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        int preZero = INT_MIN;
        int best = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            if (s[i] == '1') {
                ones += len;
            } else {
                best = max(best, preZero + len);
                preZero = len;
            }
            i = j;
        }
        return ones + best;
    }
};