class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> orig_cnt(26, 0);
        for (char c : s) orig_cnt[c - 'a']++;
        for (int i = n - 1; i >= 0; --i) {
            vector<int> cnt = orig_cnt;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                if (cnt[c] > 0) cnt[c]--;
                else {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            int target_char = target[i] - 'a';
            int next_char = -1;
            for (int c = target_char + 1; c < 26; ++c) {
                if (cnt[c] > 0) {
                    next_char = c;
                    break;
                }
            }
            if (next_char == -1) continue;
            string res = target.substr(0, i);
            res += (char)('a' + next_char);
            cnt[next_char]--;
            for (int c = 0; c < 26; ++c) {
                while (cnt[c] > 0) {
                    res += (char)('a' + c);
                    cnt[c]--;
                }
            }
            return res;
        }
        vector<int> cnt = orig_cnt;
        string smallest_s = "";
        for (int c = 0; c < 26; ++c) {
            while (cnt[c] > 0) {
                smallest_s += (char)('a' + c);
                cnt[c]--;
            }
        }
        if (smallest_s > target) return smallest_s;
        return "";
    }
};