class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string left = "";
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, 'a' + i);
            if (freq[i] % 2)
                mid = 'a' + i;
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};