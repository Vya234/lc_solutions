class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int openIdx = st.top();
                st.pop();
                pair[openIdx] = i;
                pair[i] = openIdx;
            }
        }
        string result;
        int direction = 1; 
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];        
                direction = -direction; 
            } else {
                result += s[i];
            }
        }
        return result;
    }
};