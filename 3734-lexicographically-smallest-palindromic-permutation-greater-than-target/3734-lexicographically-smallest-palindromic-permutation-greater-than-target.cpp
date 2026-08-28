class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int m = n / 2;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int odd_cnt = 0;
        char mid_char = 0;
        for (int c = 0; c < 26; ++c) {
            if (freq[c] % 2 != 0) {
                odd_cnt++;
                mid_char = 'a' + c;
            }
        }
        if (odd_cnt > 1) return "";
        vector<int> half_freq(26, 0);
        for (int c = 0; c < 26; ++c) {
            half_freq[c] = freq[c] / 2;
        }
        auto buildPalindrome = [&](const string& first_half) {
            string second_half = first_half;
            if (n % 2 != 0) {
                reverse(second_half.begin(), second_half.end());
                return first_half + mid_char + second_half;
            } else {
                reverse(second_half.begin(), second_half.end());
                return first_half + second_half;
            }
        };
        for (int i = m; i >= 0; --i) {
            vector<int> cnt = half_freq;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                if (cnt[c] > 0) {
                    cnt[c]--;
                } else {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            int start_char = (i < m) ? (target[i] - 'a' + 1) : 0;
            for (int c = start_char; c < 26; ++c) {
                if (i < m && cnt[c] == 0) continue;
                vector<int> cur_cnt = cnt;
                string first_half = target.substr(0, i);
                if (i < m) {
                    first_half += (char)('a' + c);
                    cur_cnt[c]--;
                }
                for (int ch = 0; ch < 26; ++ch) {
                    while (cur_cnt[ch] > 0) {
                        first_half += (char)('a' + ch);
                        cur_cnt[ch]--;
                    }
                }
                string cand = buildPalindrome(first_half);
                if (cand > target) return cand;
            }
        }
        return "";
    }
};