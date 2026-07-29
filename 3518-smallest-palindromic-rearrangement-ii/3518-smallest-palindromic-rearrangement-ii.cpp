class Solution {
public:
    long long countPermutations(int L, const vector<int>& freq, long long limit) {
        long long res = 1;
        int current_L = 1;
        vector<int> cur_freq = freq;
        for (int ch = 0; ch < 26; ++ch) {
            for (int f = 1; f <= cur_freq[ch]; ++f) {
                res = res * current_L / f;
                current_L++;
                if (res > limit) return limit + 1; 
            }
        }
        return res;
    }
    string smallestPalindrome(string s, long long k) {
        int n = s.length();
        int half_len = n / 2;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        vector<int> half_freq(26, 0);
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) mid_char = 'a' + i;
        }
        long long total = countPermutations(half_len, half_freq, k);
        if (total < k) return "";
        string left_half = "";
        int rem_len = half_len;
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] == 0) continue;
                half_freq[c]--;
                long long cnt = countPermutations(rem_len - 1, half_freq, k);
                if (cnt >= k) {
                    left_half += (char)('a' + c);
                    rem_len--;
                    break; 
                } else {
                    k -= cnt;
                    half_freq[c]++; 
                }
            }
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        if (n % 2 != 0) return left_half + mid_char + right_half;
        else return left_half + right_half;
    }
};