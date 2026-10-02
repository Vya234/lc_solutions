class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current = "";
        auto backtrack = [&](auto& self, int open, int close) -> void {
            if (current.length() == 2 * n) {
                res.push_back(current);
                return;
            }
            if (open < n) {
                current.push_back('(');
                self(self, open + 1, close);
                current.pop_back();
            }
            if (close < open) {
                current.push_back(')');
                self(self, open, close + 1);
                current.pop_back();
            }
        };
        backtrack(backtrack, 0, 0);
        return res;
    }
};