class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        int first_min = 0;
        int last_max = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] < s[first_min]) first_min = i;
            if (s[i] >= s[last_max]) last_max = i;
        }
        if (first_min == 0 || last_max == n - 1) return 1;
        if (first_min == n - 1 && last_max == 0) return 3;
        return 2;
    }
};