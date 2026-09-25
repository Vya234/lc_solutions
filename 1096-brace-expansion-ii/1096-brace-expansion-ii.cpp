class Solution {
private:
    set<string> parse(const string& s, int& i) {
        set<string> total_union;
        set<string> current_group = {""};
        while (i < s.length() && s[i] != '}') {
            if (s[i] == ',') {
                total_union.insert(current_group.begin(), current_group.end());
                current_group = {""};
                i++;
            } else if (s[i] == '{') {
                i++;
                set<string> nested = parse(s, i);
                i++;
                set<string> next_group;
                for (const string& a : current_group) {
                    for (const string& b : nested) {
                        next_group.insert(a + b);
                    }
                }
                current_group = move(next_group);
            } else {
                string word = "";
                while (i < s.length() && isalpha(s[i])) {
                    word += s[i++];
                }
                set<string> next_group;
                for (const string& a : current_group) {
                    next_group.insert(a + word);
                }
                current_group = move(next_group);
            }
        }
        total_union.insert(current_group.begin(), current_group.end());
        return total_union;
    }
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> resultSet = parse(expression, i);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};