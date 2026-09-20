class Solution {
public:
    int reverseDegree(string s) {
        int total_sum = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int reverse_val = 'z' - s[i] + 1;
            total_sum += reverse_val * (i + 1);
        }
        return total_sum;
    }
};