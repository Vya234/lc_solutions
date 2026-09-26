class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        string result;
        string current_key;
        bool in_bracket = false;
        for (char ch : s) {
            if (ch == '(') {
                in_bracket = true;
                current_key.clear();
            } else if (ch == ')') {
                in_bracket = false;
                auto it = dict.find(current_key);
                if (it != dict.end()) result += it->second;
                else result += '?';
            } else {
                if (in_bracket) current_key += ch;
                else result += ch;
            }
        }
        return result;
    }
};