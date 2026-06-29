class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        if(s=="") return 0;
        int len=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else len = max(len, i - st.top());
            }
        }
        return len;
    }
};