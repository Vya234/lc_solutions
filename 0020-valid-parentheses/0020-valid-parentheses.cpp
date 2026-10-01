class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {{')', '('},{'}', '{'},{']', '['}};
        for (char ch : s) {
            if (matching.count(ch)) {
                if (st.empty() || st.top() != matching[ch]) return false;
                st.pop();
            } else st.push(ch);
        }
        return st.empty();
    }
};