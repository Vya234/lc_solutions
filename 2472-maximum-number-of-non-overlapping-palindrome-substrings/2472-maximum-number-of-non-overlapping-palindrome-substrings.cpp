class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = 0; 
        for (int i = 0; i < n; ++i) {
            if (i - k + 1 >= last_end && isPalindrome(s, i - k + 1, i)) {
                count++;
                last_end = i + 1;
            }
            else if (i - k >= last_end && isPalindrome(s, i - k, i)) {
                count++;
                last_end = i + 1;
            }
        }
        return count;
    }
};