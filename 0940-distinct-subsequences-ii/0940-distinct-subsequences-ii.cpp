class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> last(26, 0);
        long long MOD = 1e9 + 7;
        for (char ch : s) {
            int c = ch - 'a';
            long long current_total = 1; 
            for (int k = 0; k < 26; ++k) {
                current_total = (current_total + last[k]) % MOD;
            }
            last[c] = current_total;
        }
        long long total_distinct = 0;
        for (int k = 0; k < 26; ++k) {
            total_distinct = (total_distinct + last[k]) % MOD;
        }
        return total_distinct;
    }
};