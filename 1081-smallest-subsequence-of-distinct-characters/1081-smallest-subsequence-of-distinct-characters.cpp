class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        vector<bool> vis(26, false);
        stack<char> st;
        for (char c : s) freq[c]++;
        for (char c : s) {
            freq[c]--;
            if (vis[c - 'a']) continue;
            while (!st.empty() && st.top() > c && freq[st.top()] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            vis[c - 'a'] = true;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};